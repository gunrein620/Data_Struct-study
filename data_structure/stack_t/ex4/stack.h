#include "elem.h"
#define MAX_SIZE 10

typedef struct stack
{
  elem_t data[MAX_SIZE];
  int top;
}stack_s;

void init(stack_s *st);
int is_full(stack_s *st);
int is_empty(stack_s *st);
void push(stack_s *st, elem_t e);
elem_t pop(stack_s *st);
elem_t peek(stack_s *st);

