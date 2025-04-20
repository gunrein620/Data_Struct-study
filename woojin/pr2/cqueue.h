#pragma once
#include "elem.h"
#define MAX_QUEUE_SIZE 10

struct tag
{
    int front, rear;
    elem_t data[MAX_QUEUE_SIZE];
} typedef cqueue_t;

void init(cqueue_t*);
int is_full(cqueue_t*);
int is_empty(cqueue_t*);
void enqueue(cqueue_t*, elem_t);
elem_t dequeue(cqueue_t*);
elem_t peek(cqueue_t*);