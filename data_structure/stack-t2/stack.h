#pragma once
#include "elem.h"
#define MAX_SIZE 20

typedef struct stack_s{
  elem_t data[MAX_SIZE];
  int top;
}stack_s;

void init(stack_s);
int is_full(stack_s);
int is_empty(stack_s);
void push(stack_s, elem_t);
elem_t pop(stack_s);
elem_t peek(stack_s);
