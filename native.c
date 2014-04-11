#include "forth.h"
#include "stdio.h"
#include "stdlib.h"

#define var unsigned int

extern yield_execution(unsigned int);

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

//g r ret ret
void ret(){
	ASSERT(R_SP > 0)
	PC = R_STACK[ --R_SP ];
}

//g r dump f_dump
void f_dump(){
	var i = 0;
	while(i < SP)
		printf("%X ", STACK[i++]);
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

//g r status status
void status(){
	var start = (var) HEAP;
	var size = ((var) HERE) - start;
	printf("%i/%i bytes.", size, HEAP_SIZE);
}

//g c lit lit
void lit(){
	push(*((var*) PC + 4));
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
	yield_execution(address);
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
	printf("%X", pop());
}

//g r .s dot_s
void dot_s(){
	char* str = (char*) pop();
	puts(str);
}

//g r ok ok
void ok(){
	puts(" OK.");
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
	printf("WRITING VALUE: %X\n", value);
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
	char input_buffer[128];
	memset((void*) input_buffer, 0, 128);
	gets(input_buffer);
	memcpy((void*) HERE, (void*) input_buffer, 128);
	push(HERE);
	HERE += 128;
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
	
	while(current_word != 0){
		printf("%s ", ((char*) current_word + 4));
		current_word = *((unsigned int*) current_word);
	}
}

//g r leave-clean leave_clean
void leave_clean(){
	exit(0);
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

//g r cfind cfind
void cfind(){
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
	
	push(0);
}

//g r cfa cfa
void cfa(){
	var address = pop();
	char* name = (char*) (address + 4);
	push(address + 4 + strlen(name) + 1);
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

var char_pos;
var ibuffer_length;
char* ibuffer;

//g r word word
void word(){
	while(char_pos < ibuffer_length){
		if(ibuffer[char_pos] == 0){
			char_pos++;
			continue;
		}
		
		push(((var) ibuffer) + char_pos);
		char_pos += strlen((char*) (((var) ibuffer) + char_pos));
		return;
	}

	push(0);
}

//g r number? is_number
void is_number(){
	char* str = (char*) pop();
	
	printf("IS_NUMBER? %s\n", str);

	int i;
	for(i = 0; i < strlen(str); i++){
		if((str[i] < '0') || (str[i] > '9')){
			push(0);
			return;
		}
	}

	push(1);
}

//g r number number
void number(){
	char* str = (char*) pop();
	var num = atoi(str);
	push(num);
}

//g r eval eval
void eval(){
	ibuffer = pop();
	ibuffer_length = pop();
	char_pos = 0;

	for(;;){
		if(!state){
			word();						//word* --
			dup();						//word* -- word* --
	
			if(!pop()){					//word* --
				drop();					//--
				return;
			}
			
			dup();						//word* -- word* --
			is_number();					//word* -- flag
	
			if(!pop()){
				find();					//addr --
				dup();					//addr -- addr --
			
				if(!pop()){				//addr --
					puts("WORD NOT FOUND");
					drop();				//--
					return;
				}
	
				cfa();					//code* --
				run_word();				//output -- ... --
			}
			
			else{
				number();				//num --
			}
		}

		else{
			word();			//word* --
			dup();			//word* -- word* --

			if(!pop()){		//word* --
				drop();			//--
				return;
			}

			dup();			//word* -- word* --
			is_number();		//word* -- flag --

			if(pop()){		//word* --
				push((var) &lit);	//word* -- lit* --
				comma();		//word* --
				number();		//num --
				comma();		//--
				continue;
			}
			
			dup();			//word* -- word* --
			cfind();		//word* -- addr --
			
			if(pop()){		//word* --
				cfind();		//addr --
				cfa();			//code* --
				run_word();		//output --
				continue;
			}

			dup();			//word* -- word* --
			find();			//word* -- addr --

			if(pop()){		//word* --
				push((var) &call);	//word* -- call* --
				comma();		//word* --
				find();			//addr --
				cfa();
				comma();
				continue;
			}

			drop();			//--
			puts("S=1 WORD NOT FOUND");
			return;
		}
	}
}

//g r strhere strhere
void strhere(){
	char* dest = (char*) HERE;
	char* src = (char*) pop();

	int i;
	for(i = 0; i < strlen(src); i++){
		dest[i] = src[i];
	}

	dest[strlen(src) + 1] = 0;
	HERE += strlen(src) + 1;
}

//g r create r_create
void r_create(){
	word();			//word* --
	dup();			//word* -- word* --
	
	if(!pop()){
		drop();		//--
		puts("ERR: END OF INPUT");
		return;
	}

	var temp_here = HERE;
	get_last();		//word* -- last --
	comma();		//word* --
	R_LAST = temp_here;
	strhere();		//--
}

//r r : r_create o_bracket

//g c ; semicolon
void semicolon(){
	push((var) &ret);
	comma();
	state = 0;
}

//g r last get_last
void get_last(){
	push(R_LAST);
}

//g r c-last get_c_last
void get_c_last(){
	push(C_LAST);
}

//g r last! set_last
void set_last(){
	R_LAST = pop();
}

//g r c-last! set_c_last
void set_c_last(){
	C_LAST = pop();
}

//g r [ o_bracket
void o_bracket(){
	state = 1;
}

//g c ] c_bracket
void c_bracket(){
	state = 0;
}

//g r repl repl
void repl(){
	ok();
	
	for(;;){
		get_forth_line();
		dup();
		push(128);
		swap();
		zero_buffer();
		push(128);
		swap();
		eval();
		ok();
	}
}
