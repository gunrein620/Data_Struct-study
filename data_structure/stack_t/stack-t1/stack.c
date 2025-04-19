#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void init(stack_s* sp)
{
  sp->top = 0;
}

void push(stack_s* s, elem_t e)
{
  if (is_full(s)) {
    fprintf(stderr, "스택이 꽉 찼습니다.\n");
    return;
  }
  s->data[(s->top)++] = e;
}

elem_t pop(stack_s* s)
{
  if (is_empty(s)) {
    fprintf(stderr, "스택이 비었습니다.\n");
    return err_elem;
  }
  return s->data[--(s->top)];
}

int is_empty(stack_s* s)
{
  return (s->top == 0);
}

int is_full(stack_s* s)
{
  return (s->top == STACK_SIZE);
}

elem_t peek(stack_s* sp)
{
  return sp->data[sp->top - 1];
}

void print_stack(stack_s* s) {
	for (int i = 0; i < s->top; i++)
		printf("%4s", str(s->data[i]));
	for (int i = s->top; i < STACK_SIZE; i++)
		printf("%4s", " ");
	printf("\n");
}








