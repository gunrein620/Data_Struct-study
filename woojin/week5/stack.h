#pragma once
#include "elem.h"
#define MAX_STACK_SIZE 50
typedef struct {
	elem_t data[MAX_STACK_SIZE];
	int top;
} stack_t;
void push(stack_t* s, elem_t e);
elem_t pop(stack_t* s);
int is_empty(stack_t* s);
int is_full(stack_t* s);
void init_stack(stack_t* s);
void print_stack(stack_t* s);
char* str(elem_t e);