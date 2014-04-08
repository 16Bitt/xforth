#include "forth.h"
#include "stdio.h"

int run(forth_env_t* job){	
	current = job;
	printf("%X:%X\n", (unsigned int) current, (unsigned int) PC);

	while(*((unsigned int*) PC) != 0){
		unsigned int ptr = *((unsigned int*) PC);
		void (*function)(void) = (void (*)(void)) ptr;
		function();
		PC += 4;
	}

	return STACK[SP - 1];
}
