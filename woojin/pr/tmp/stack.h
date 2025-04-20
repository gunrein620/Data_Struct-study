#pragma once
#include "elem.h"
#define MAX_SIZE 20

struct a
{
    int top;
    elem_t datas[MAX_SIZE];
} typedef stack_t;

void init(stack_t*);
void push(stack_t*, elem_t);
elem_t pop(stack_t*);
int is_empty(stack_t*);
int is_full(stack_t*);
elem_t peek(stack_t*);

