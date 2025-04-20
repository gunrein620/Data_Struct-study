#pragma once
#include "elem.h"
#define MAX_STACK_SIZE 10

struct tag
{
    int top;
    elem_t data[MAX_STACK_SIZE];
} typedef stack_t;

void init(stack_t*);
int is_full(stack_t*);
int is_empty(stack_t*);
void push(stack_t*, elem_t);
elem_t pop(stack_t*);
elem_t peek(stack_t*);