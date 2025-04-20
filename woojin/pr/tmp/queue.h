#pragma once
#include "elem.h"
#define MAX_SIZE 20

struct queue
{
    int rear, front;
    elem_t data[MAX_SIZE];
} typedef queue_t;

void init(queue_t*);
int is_full(queue_t*);
int is_empty(queue_t*);
void enqueue(queue_t*, elem_t);
elem_t dequeue(queue_t*);
elem_t peek(queue_t*);

