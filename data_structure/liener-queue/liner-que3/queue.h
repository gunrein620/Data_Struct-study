#pragma once
#include "elem.h"
#define MAX_SIZE 10

typedef struct tag
{
  elem_t data[MAX_SIZE];
  int front, rear;
}que;

void init(que *qu);
int is_full(que *qu);
int is_empty(que *qu);
void enque(que *qu, elem_t e);
elem_t deque(que *qu);
elem_t peek(que *qu);
void print(que * qu);


