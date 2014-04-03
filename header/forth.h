#ifndef FORTH_H
#define FORTH_H

typedef struct{
	unsigned int 	id_unique,		//job id
			
			pc,			//execution index
			sp,			//data stack index
			r_sp,			//return stack index
			p_sp,			//parallell stack index
			here,			//heap current location

			stack_size,		//size of data stack
			r_stack_size,		//size of return stack
			p_stack_size,		//size of parallell stack
			heap_size;		//size of heap
	
	unsigned int	last;			//last runtime word
	unsigned int	c_last;			//last compile time word

	unsigned int*	stack;			//data stack address
	unsigned int*	r_stack;		//return stack address
	unsigned int*	p_stack;		//parallell stack address

	void*		heap;			//heap address
} forth_env_t;

extern forth_env_t* current;
extern int line;

#define PC 		current->pc
#define SP 		current->sp
#define R_SP 		current->r_sp
#define P_SP		current->p_sp
#define HERE		current->here

#define STACK_SIZE	current->stack_size
#define R_STACK_SIZE	current->r_stack_size
#define P_STACK_SIZE	current->p_stack_size
#define HEAP_SIZE	current->heap_size

#define R_LAST		current->last
#define C_LAST		current->c_last

#define STACK		current->stack
#define R_STACK		current->r_stack
#define P_STACK		current->p_stack

#define HEAP		current->heap

void fail(int line, char* filename);
#define ASSERT(a) (a) ? : fail(__LINE__, __FILE__);

#endif
