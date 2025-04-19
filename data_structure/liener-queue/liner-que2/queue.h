#pragma once 

#include "elem.h"
#define MAX_SIZE 10

typedef struct que
{
  elem_t data[MAX_SIZE];
  elem_t front, rear;
}qu_t;

void init(qu_t *qu);
int is_full(qu_t *qu);
int is_empty(qu_t *qu);
void enque(qu_t *qu,elem_t e);
elem_t deque(qu_t *qu);
void print_que(qu_t *qu);



