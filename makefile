SOURCES = main.o globals.o vm.o error.o native.o hardcode.o loader.o
CFLAGS 	= -m32 -Iheader/ -w
LDFLAGS	= -w

all: $(SOURCES)
	gcc -m32 $(SOURCES) -obuild/cforth

hardcode.c:
	ruby generate.rb native.c

clean:
	-rm *.o hardcode.c build/cforth

run: all
	./build/cforth

install: all
	cp build/cforth /bin/
