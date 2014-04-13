#include "forth.h"
#include "stdio.h"
#include "stdlib.h"

void dputs(char* str){
	if(flag_debug)
		puts(str);
}

void fail(int line, char* filename){
	printf("ASSERTION FAILED (%s:%d).\n", filename, line);
	
	exit(-1);
}
