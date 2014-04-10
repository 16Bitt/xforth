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

void yield_execution(unsigned int location){
	unsigned int initial_depth = R_SP;

	ASSERT(R_SP + 1 < R_STACK_SIZE)
	R_STACK[R_SP++] = PC;

	PC = location;

	for(;;){
		unsigned int ptr = *((unsigned int*) PC);
		void (*function)(void) = (void (*)(void)) ptr;
		function();
		
		if(R_SP == initial_depth)
			return;

		PC += 4;
	}
}
