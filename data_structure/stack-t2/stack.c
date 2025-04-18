#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void init(stack_s *sp){
  sp->top = 0;
}
int is_full(stack_s *sp){
  return sp->top == MAX_SIZE;
}
int is_empty(stack_s *sp){
  return sp->top == 0;
}
void push(stack_s *sp, elem_t e){
  if (is_full(sp)) {
    printf("스택이 가득참");
    return 0;
  }
  return sp->data[sp->top++] = e;
}
elem_t pop(stack_s *sp){
  if (is_empty(sp)){
    printf("스택이 비었음");
  }
  return sp->data[--sp->top];
}
elem_t peek(stack_s *sp) {
  return sp->data[sp->top -1];
}

