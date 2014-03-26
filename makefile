SOURCES = main.o globals.o error.o
CFLAGS 	= -m32 -Iheader/

all: $(SOURCES)
	gcc -m32 $(SOURCES) -obuild/cforth

clean:
	-rm *.o build/cforth
