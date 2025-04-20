#pragma once
#include "elem.h"
#define MAX_SIZE 5

typedef struct tag{
  elem_t data[MAX_SIZE];
  int front, rear;
}cque_cq;

void init(cque_cq *cq);
int is_full(cque_cq *cq);
int is_empty(cque_cq *cq);
void enque(cque_cq *cq, elem_t e);
elem_t deque(cque_cq *cq);
elem_t peek(cque_cq *cq);