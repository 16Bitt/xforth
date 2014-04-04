#include "forth.h"
#include "stdlib.h"
#include "string.h"

extern void hard_load();

//create empty forth job
forth_env_t* load_new(unsigned int heap_size, unsigned int stack_size){
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

void forth_start(char* word){
	unsigned int current_word = R_LAST;

	while(current_word != 0){
		if(!strcmp(word, (char*) current_word + 4)){
			PC = strlen((char*) current_word + 4) + 1;
			return;
		}

		current_word = *((unsigned int*) current_word);
	}

	//If execution reaches this point, it's time to error out, as the word does not exist
	ASSERT(1 == 0)
}
