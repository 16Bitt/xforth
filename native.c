#include "forth.h"
#include "stdio.h"
#include "stdlib.h"

#define var unsigned int

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

//g c exit ret
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
	
	int count = 0;
	while(start[count] != 0)
		count++;
	
	push((unsigned int) count);
}
