#include "forth.h"
void hard_load(){
unsigned int write_location = HERE, temp_last = 0;
extern void ret();
extern void f_dump();
extern void call();
extern void status();
extern void lit();
extern void jump();
extern void zjump();
extern void run_word();
extern void at();
extern void c_at();
extern void set();
extern void c_set();
extern void swap();
extern void dup();
extern void drop();
extern void emit();
extern void dot();
extern void dot_s();
extern void ok();
extern void plus();
extern void minus();
extern void times();
extern void divide();
extern void comma();
extern void f_eq();
extern void f_lt();
extern void f_gt();
extern void f_not();
extern void f_and();
extern void f_or();
extern void f_xor();
extern void get_forth_line();
extern void forth_strlen();
extern void list();
extern void leave_clean();
extern void leave();
extern void get_state();
extern void find();
extern void cfind();
extern void cfa();
extern void zero_buffer();
extern void word();
extern void is_number();
extern void number();
extern void eval();
extern void strhere();
extern void r_create();
extern void semicolon();
extern void get_last();
extern void get_c_last();
extern void set_last();
extern void set_c_last();
extern void o_bracket();
extern void c_bracket();
extern void quote();
extern void c_quote();
extern void dot_quote();
extern void paren();
extern void c_paren();
extern void repl();
extern void allot();
extern void variable();
extern void f_if();
extern void f_then();
extern void s_to_p();
extern void p_to_s();
extern void does();
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 'm'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_dump; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &status; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'x'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &run_word; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '@'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &at; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = '@'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &c_at; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '!'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &set; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = '!'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &c_set; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 'w'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &swap; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &dup; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &drop; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'm'; write_location++;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &emit; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '.'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &dot; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '.'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &dot_s; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'k'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &ok; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '+'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &plus; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '-'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &minus; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '*'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &times; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '/'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &divide; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = ','; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &comma; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '='; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_eq; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '<'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_lt; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '>'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_gt; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_not; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_and; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_or; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'x'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_xor; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &get_forth_line; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = '-'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &forth_strlen; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &list; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'v'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = '-'; write_location++;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &leave_clean; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'v'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &leave; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &get_state; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'f'; write_location++;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &find; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = 'f'; write_location++;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &cfind; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = 'f'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &cfa; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '0'; write_location++;
*((char*) write_location) = 'b'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 'f'; write_location++;
*((char*) write_location) = 'f'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &zero_buffer; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'w'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &word; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 'm'; write_location++;
*((char*) write_location) = 'b'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = '?'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &is_number; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 'm'; write_location++;
*((char*) write_location) = 'b'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &number; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'v'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &eval; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'h'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &strhere; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &r_create; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &get_last; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = '-'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &get_c_last; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = '!'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &set_last; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = '-'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = '!'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &set_c_last; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '['; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &o_bracket; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '"'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &quote; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '('; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &paren; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &repl; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &allot; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'v'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'r'; write_location++;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 'a'; write_location++;
*((char*) write_location) = 'b'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &variable; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = '>'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &s_to_p; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '>'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &p_to_s; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = ':'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &r_create; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &o_bracket; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '.'; write_location++;
*((char*) write_location) = '"'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &quote; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &dot_s; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
R_LAST = temp_last; temp_last = 0;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'c'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &call; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'l'; write_location++;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &lit; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'j'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 'm'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &jump; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'z'; write_location++;
*((char*) write_location) = 'j'; write_location++;
*((char*) write_location) = 'u'; write_location++;
*((char*) write_location) = 'm'; write_location++;
*((char*) write_location) = 'p'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &zjump; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = ';'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &semicolon; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = ']'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &c_bracket; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '"'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &c_quote; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '.'; write_location++;
*((char*) write_location) = '"'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &dot_quote; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = '('; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &c_paren; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'i'; write_location++;
*((char*) write_location) = 'f'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_if; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 't'; write_location++;
*((char*) write_location) = 'h'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 'n'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &f_then; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
*((unsigned int*) write_location) = temp_last; temp_last = write_location; write_location += 4;
*((char*) write_location) = 'd'; write_location++;
*((char*) write_location) = 'o'; write_location++;
*((char*) write_location) = 'e'; write_location++;
*((char*) write_location) = 's'; write_location++;
*((char*) write_location) = (char) 0; write_location++;
*((unsigned int*) write_location) = (unsigned int) &does; write_location += 4;
*((unsigned int*) write_location) = (unsigned int) &ret; write_location += 4;
C_LAST = temp_last; HERE = write_location;}