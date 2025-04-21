#include "elem.h"
#define MAX_SIZE 10

typedef struct tag
{
  elemt_t data[MAX_SIZE];
  int top;
}stack_s;


//i = init full empty push pop peek print 

void init(stack_s* st);
int is_full(stack_s* st);
int is_empty(stack_s* st);
void push(stack_s* st,elemt_t e);
elemt_t pop(stack_s* st);
elemt_t peek(stack_s* st);
void print_stack(stack_s* st);
