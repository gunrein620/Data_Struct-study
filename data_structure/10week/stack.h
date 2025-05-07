#pragma once
#include "tnode.h"
#define MAX_STACK_SIZE 50
typedef tnode_t* elem_t;
struct tag {
	elem_t data[MAX_STACK_SIZE];
	int top;
};
typedef struct tag stack_t;
void init(stack_t* sp);
void push(stack_t* sp, elem_t val);
elem_t pop(stack_t* sp);
elem_t peek(stack_t* sp);
int is_empty(stack_t* sp);
int is_full(stack_t* sp);
void print_stack(stack_t* sp);