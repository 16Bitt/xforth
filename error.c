#include "forth.h"
#include "stdio.h"

void fail(int line, char* filename){
	printf("ASSERTION FAILED (%s:%d).\n", filename, line);
	
	int i;
	for(;;)
		i++;
}
