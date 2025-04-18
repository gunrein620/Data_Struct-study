#pragma once
#include "elem.h"
#define MAX_STACK_SIZE 50
typedef struct {
	elem_t data[MAX_STACK_SIZE];
	int top;
} my_stack_t;
void push(my_stack_t* s, elem_t e);
elem_t pop(my_stack_t* s);
int is_empty(my_stack_t* s);
int is_full(my_stack_t* s);
void init_stack(my_stack_t* s);
void print_stack(my_stack_t* s);
char* str(elem_t e);