#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void init(stack_s* st){
  st->top = 0;
}

int is_full(stack_s* st){
  return st->top == MAX_SIZE;
}
int is_empty(stack_s* st){
  return st->top == 0;
}
void push(stack_s* st,elemt_t e){
  if (is_full(st)) {
    printf("스택이 포화");
    return;
  }
  st->data[st->top++] = e;
}
elemt_t pop(stack_s* st){
  if (is_empty(st)){
    printf("스택이 비었음");
    return err_elem;
  }
  return st->data[--st->top];
}
elemt_t peek(stack_s* st){
  if (is_empty(st)){
    printf("스택이 비었음");
    return err_elem;
  }
  return st->data[st->top -1];
}


void print_stack(stack_s* st);