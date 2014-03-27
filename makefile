SOURCES = main.o globals.o vm.o error.o native.o hardcode.o loader.o
CFLAGS 	= -m32 -Iheader/

all: $(SOURCES)
	gcc -m32 $(SOURCES) -obuild/cforth

clean:
	-rm *.o build/cforth
