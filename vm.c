#include "forth.h"

int run(forth_env_t* job){
	current = job;
	
	while(*((unsigned int*) PC) != 0){
		void (*function)(void) = (void (*)(void)) PC;
		function();
		PC += 4;
	}

	return STACK[SP - 1];
}
