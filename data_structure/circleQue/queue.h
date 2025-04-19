#pragma once
#include "elem.h"
#define MAX_SIZE 5


typedef struct que{
  elem_t str[MAX_SIZE];
  int front, rear;
}que_t;

void init(que_t *qu);
int is_full(que_t *qu);
int is_empty(que_t *qu);
void enque(que_t *qu,elem_t);
elem_t deque(que_t *qu);
void print_que(que_t *qu);