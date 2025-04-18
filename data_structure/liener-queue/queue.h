#pragma once
#include "elem.h"
#define MAX_SIZE 20


typedef struct que{
  elem_t str[MAX_SIZE];
  int front, rear;
}que_t;

void init(que_t *qu);
int is_full(que_t *qu);
int is_empty(que_t *qu);
void enqueue(que_t *qu,elem_t);
elem_t dequeue(que_t *qu);
elem_t peek(que_t*qu);