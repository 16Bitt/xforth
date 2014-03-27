#include "forth.h"
#include "stdlib.h"
//This is for loading an empty forth job

extern void hard_load();

forth_env_t* load(unsigned int heap_size, unsigned int stack_size){
	forth_env_t* save = current;
	current = (forth_env_t*) malloc(sizeof(forth_env_t));
	
	HEAP_SIZE	= heap_size;
	STACK_SIZE	= stack_size;
	R_STACK_SIZE	= stack_size;
	P_STACK_SIZE	= stack_size;
	SP = R_SP = P_SP = 0;

	STACK = 	(unsigned int*) malloc(sizeof(unsigned int) * STACK_SIZE);
	R_STACK = 	(unsigned int*) malloc(sizeof(unsigned int) * R_STACK_SIZE);
	P_STACK =	(unsigned int*) malloc(sizeof(unsigned int) * P_STACK_SIZE);

	HEAP =		(void*) malloc(HEAP_SIZE);

	hard_load();
	
	forth_env_t* ret = current;
	current = save;

	return ret;
}
