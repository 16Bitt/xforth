#include "forth.h"
#include "stdio.h"
#include "stdlib.h"

int flag_debug;
int flag_echo;
unsigned int init_stack_size;
unsigned int init_heap_size;
char* entry_point;

void check_arguments(int num){
	if(num != 6){
		puts("Not enough arguments to initialize a forth environment");
		exit(-1);
	}
}

void set_arguments(char** argv, int argc){
	check_arguments(argc);

	flag_debug = strcmp(argv[1], "on")? 0 : 1;
	flag_echo = strcmp(argv[2], "on")? 0 : 1;
	
	init_stack_size = atoi(argv[3]);
	init_heap_size = atoi(argv[4]);

	entry_point = argv[5];
}
