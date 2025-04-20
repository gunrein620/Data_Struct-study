#include <stdio.h>
#include "stack.h"

void init(stack_s *st){
  st->top = 0;
}
int is_full(stack_s *st){
   return st->top == MAX_SIZE;
}
int is_empty(stack_s *st){
  return st->top == 0;
}
void push(stack_s *st, elem_t e){
  if (is_full(st)){
    printf("스택 포화");
    return;
  }
  st->data[st->top++] = e;
}
elem_t pop(stack_s *st) {
  if (is_empty(st)){
    printf("스택 빔");
    return err_elem;
  }
  //st->top = st->top -1
  return st->data[--st->top];
}
elem_t peek(stack_s *st){
  if (is_empty(st)){
    printf("스택 빔");
    return err_elem;
  }
  return st->data[st->top -1];// st->top -1
}


