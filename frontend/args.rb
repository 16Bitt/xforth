#!/usr/bin/env ruby

#A Simple wrapper for cli arguments
#Simply pass it your options with ArgParse.new ["-o", "--verbose", "--help"]
#The error argument will print a custom error if it fails

class ArgParse
	def initialize options = [], error = ""
		@list = ARGV
		@target = nil
		@options = options
		@values = [nil] * (options.length)
		@error = error
		parse
	end

	def parse
		index = 0
		
		while index < @list.length
			val = @list[index]
			
			opt = 0
			while opt < @options.length
				if @options[opt] == val
					index += 1
					@values[opt] = @list[index]
					break
				end

				opt += 1
			end
			
			if opt >= @options.length
				if @target
					abort "Unrecognized option '#{@list[index]}'\n#{@error}"
				end
				
				@target = @list[index]
			end

			index += 1
		end

		if not target
			abort "No target on command line\n#{@error}"
		end
	end

	def getValue option
		for i in 0...@options.length
			if @options[i] === option
				return @values[i]
			end
		end

		return nil
	end

	def target
		@target
	end
end
