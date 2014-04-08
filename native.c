#include "forth.h"
#include "stdio.h"
#include "stdlib.h"

#define var unsigned int

unsigned int state = 0;

unsigned int pop(){
	ASSERT(SP > 0)
	return STACK[--SP];
}

void push(unsigned int value){
	ASSERT(SP + 1 < STACK_SIZE)
	STACK[SP++] = value;
}

unsigned int p_pop(){
	ASSERT(P_SP > 0)
	return P_STACK[--P_SP];
}

void p_push(unsigned int value){
	ASSERT(P_SP + 1 < P_STACK_SIZE)
	P_STACK[P_SP++] = value;
}

//g c ret ret
void ret(){
	ASSERT(R_SP > 0)
	PC = R_STACK[ --R_SP ];
}

//g c docol call
void call(){
	unsigned int address = *((unsigned int*)PC + 4);
	ASSERT(address != 0)
	PC += 4;
	
	ASSERT(R_SP + 1 < R_STACK_SIZE)
	R_STACK[R_SP++] = PC;
	PC = address;
}

//g c lit lit
void lit(){
	push(*((unsigned int*) PC + 4));
	PC += 4;
}

//g c jump jump
void jump(){
	PC = *((unsigned int*) PC + 4) - 4;
}

//g c zjump zjump
void zjump(){
	if(pop())
		PC = *((unsigned int*) PC + 4) - 4;
}

//g r exec run_word
void run_word(){
	var address = pop();
	ASSERT(address != 0)
	ASSERT(R_SP + 1 < R_STACK_SIZE)

	R_STACK[R_SP++] = PC;
	PC = address;
}

//g r @ at
void at(){
	push(*((unsigned int*) pop()));
}

//g r c@ c_at
void c_at(){
	push((unsigned int) *((char*) pop()));
}

//g r ! set
void set(){
	unsigned int dest = pop();
	unsigned int data = pop();

	*((unsigned int*) dest) = data;
}

//g r c! c_set
void c_set(){
	unsigned int dest = pop();
	unsigned int data = pop();

	*((char*) dest) = (char) data;
}

//g r swap swap
void swap(){
	var a = pop();
	var b = pop();
	push(a);
	push(b);
}

//g r dup dup
void dup(){
	var a = pop();
	push(a);
	push(a);
}

//g r drop drop
void drop(){
	pop();
}

//g r emit emit
void emit(){
	printf("%c", (char) pop());
}

//g r . dot
void dot(){
	printf("%d", pop());
}

//g r ok ok
void ok(){
	printf(" OK. ");
}

//g r + plus
void plus(){
	push(pop() + pop());
}

//g r - minus
void minus(){
	unsigned int a = pop();
	unsigned int b = pop();

	push(b - a);
}

//g r * times
void times(){
	push(pop() * pop());
}

//g r / divide
void divide(){
	unsigned int a = pop();
	unsigned int b = pop();

	ASSERT(a != 0)

	push(b / a);
}

//g r , comma
void comma(){
	int value = pop();
	*((unsigned int*) HERE) = value;
	HERE += 4;
}

//g r = f_eq
void f_eq(){
	if(pop() == pop())
		push(1);
	else
		push(0);
}

//g r < f_lt
void f_lt(){
	var a = pop();
	var b = pop();
	
	if(b < a)
		push(1);
	else
		push(0);
}

//g r > f_gt
void f_gt(){
	var a = pop();
	var b = pop();

	if(b > a)
		push(1);
	else
		push(0);
}

//g r not f_not
void f_not(){
	push(!pop());
}

//g r and f_and
void f_and(){
	push(pop() & pop());
}

//g r or f_or
void f_or(){
	push(pop() | pop());
}

//g r xor f_xor
void f_xor(){
	push(pop() ^ pop());
}

//g r line get_forth_line
void get_forth_line(){
	char input_buffer[512];
	memset((void*) input_buffer, 0, 512);
	gets(input_buffer);
	memcpy((void*) HERE, (void*) input_buffer, 512);
	push(HERE);
	HERE += 512;
}

//g r c-len forth_strlen
void forth_strlen(){
	char* start = (char*) pop();
	
	int count = strlen(start);
	push((unsigned int) count);
}

//g r list list
void list(){
	unsigned int current_word = R_LAST;
	
	while(current != 0){
		printf("%s ", ((char*) current_word + 4));
		current_word = *((unsigned int*) current_word);
	}
}

//g r leave leave
void leave(){
	exit((int) pop());
}

//g r state get_state
void get_state(){
	push((unsigned int) &state);
}

//g r find find
void find(){
	unsigned int current_word;
	char* name = (char*) pop();

	if(state){
		current_word = C_LAST;
		while(current_word != 0){
			char* word_name = (char*) (current_word + 4);
			
			if(!strcmp(name, word_name)){
				push(current_word);
				return;
			}

			current_word = *((unsigned int*) current_word);
		}
	}
	
	current_word = R_LAST;
	while(current_word != 0){
		char* word_name = (char*) (current_word + 4);

		if(!strcmp(word_name, name)){
			push(current_word);
			return;
		}

		current_word = *((unsigned int*) current_word);
	}

	push(0);
}

//g r cfa cfa
void cfa(){
	char* name = (char*) (pop() + 4);
	push(strlen(name) + 1);
}

//g r 0buffer zero_buffer
void zero_buffer(){
	char* buffer = (char*) pop();
	unsigned int size = pop();

	unsigned int i;
	for(i = 0; i < size; i++){
		if(buffer[i] == ' ')
			buffer[i] = 0;
		else if(buffer[i] == '\n')
			buffer[i] = 0;
	}
}

#define threshold 4

//g r eval eval
void eval(){
	char* words = (char*) pop();
	unsigned int buffer_length = pop();

	var i = 0;
	while(i < buffer_length){
		if(words[i] == 0){
			i++;
			continue;
		}

		var name = ((var) words) + i;
		var word_length = strlen((char*) name);
		
		push(name);				//name --
		find();					//addr --
		dup();					//addr -- addr --

		if(!pop()){				//? addr --
			puts(" WORD NOT FOUND.");
			drop();				//? --
			return;
		}

		cfa();					//code* --
		run_word();

		i += word_length;
	}
}

//g r repl repl
void repl(){
	for(;;){
		get_forth_line();	//buffer
		dup();			//buffer -- buffer
		push(512);		//buffer -- buffer -- 512
		swap();			//buffer -- 512 -- buffer
		zero_buffer();		//buffer
		push(512);		//buffer -- 512
		swap();			//512 -- buffer
		eval();			//--
		ok();
	}
}
