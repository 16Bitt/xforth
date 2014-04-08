#include "forth.h"
#include "stdio.h"
#include "stdlib.h"

extern forth_env_t* load_new(unsigned int, unsigned int);
extern void forth_start(char*);
extern int run(forth_env_t*);

int main(){
	puts("Starting C_FORTH:");
	forth_env_t* program = load_new(4096, 512);
	puts("Loaded new program...");
	current = program;
	forth_start("repl");
	puts("Set entry point to the repl...");
	current = program;
	return run(current);
}
