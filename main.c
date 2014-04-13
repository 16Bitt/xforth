#include "forth.h"
#include "stdio.h"
#include "stdlib.h"

extern forth_env_t* load_new(unsigned int, unsigned int);
extern void forth_start(char*);
extern int run(forth_env_t*);

int main(int argc, char** argv){
	set_arguments(argv, argc);
	current = load_new(init_heap_size, init_stack_size);
	forth_start(entry_point);
	return run(current);
}
