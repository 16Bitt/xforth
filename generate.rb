#!/usr/bin/env ruby

if ARGV.length < 1
	abort "not enough arguments"
end

file = File.new ARGV[0], 'r'

r_words = []
c_words = []

r_defs = []
c_defs = []

output = "#include \"forth.h\"\nvoid hard_load(){\nunsigned int write_location = HERE, temp_last = 0;\n"

puts "Parsing file..."
flag = nil
file.each do |line|
	if flag
		str = line
		str.gsub! "{", ";"
		str = "extern " + str
		output += str
		flag = nil
	end

	arr = line.split " "
	if arr[0] == "//g"
		case arr[1]
			when "r"
				flag = true
				r_words.push (arr[2] + " " + arr[3])
			when "c"
				flag = true
				c_words.push (arr[2] + " " + arr[3])
			else
				abort "Unrecognized generation option: #{arr[1]}"
		end
	elsif arr[0] == "//r"
		case arr[1]
			when "r"
				r_defs.push arr[2...arr.length]
			when "c"
				c_defs.push arr[2...arr.length]
			else
				abort "Unrecognized generation option: #{arr[1]}"
		end
	end
end

file.close

puts "Found #{c_words.length + c_defs.length} compile time words and #{r_words.length + r_defs.length} runtime words."

file = File.new "hardcode.c", "w"
file.puts output

puts "Hardcoding runtime words..."
r_words.each do |combo|
	arr = combo.split " "
	fname = arr[0]
	cname = arr[1]

	file.puts "*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;"

	for i in 0...fname.length
		file.puts "*((char*) write_location) = '#{fname[i].chr}'; write_location++;"
	end
	file.puts "*((char*) write_location) = (char) 0; write_location++;"
	file.puts "*((unsigned int*) write_location) = (unsigned int) &#{arr[1]}; write_location += 4;"
	file.puts "*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;"
end

puts "Generating simple definitions (run time)..."
r_defs.each do |list|
	name = list[0]
	words = list[1...list.length]
	
	file.puts "*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;"
	for i in 0...fname.length
		file.puts "*((char*) write_location) = '#{fname[i].chr}'; write_location++;"
	end

	file.puts "*((char*) write_location) = (char) 0; write_location++;"
	
	words.each do |word|
		file.puts "*((unsigned int*) write_location) = (unsigned int) &#{word}; write_location += 4;"
	end

	file.puts "*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;"
end

file.puts "R_LAST = temp_last; temp_last = 0;"

puts "Hardcoding compile time words..."
c_words.each do |combo|
	arr = combo.split " "
	fname = arr[0]
	cname = arr[1]

	file.puts "*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;"

	for i in 0...fname.length
		file.puts "*((char*) write_location) = '#{fname[i].chr}'; write_location++;"
	end

	file.puts "*((char*) write_location) = (char) 0; write_location++;"
	file.puts "*((unsigned int*) write_location) = (unsigned int) &#{arr[1]}; write_location += 4;"
	file.puts "*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;"
end

puts "Generating simple definitions (compile time)..."
c_defs.each do |list|
	name = list[0]
	words = list[1...list.length]
	
	file.puts "*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;"
	for i in 0...fname.length
		file.puts "*((char*) write_location) = '#{fname[i].chr}'; write_location++;"
	end

	file.puts "*((char*) write_location) = (char) 0; write_location++;"
	
	words.each do |word|
		file.puts "*((unsigned int*) write_location) = (unsigned int) &#{word}; write_location += 4;"
	end

	file.puts "*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;"
end

file.puts "C_LAST = temp_last; HERE = write_location;}"
file.close

puts "Success."
