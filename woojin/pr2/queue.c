#include <stdio.h>
#include "queue.h"


void init(queue_t* q)
{
    q->front = 0;
    q->rear = 0;
}

int is_full(queue_t* q)
{
    return q->rear == MAX_QUEUE_SIZE;
}

int is_empty(queue_t* q)
{
    return q->rear == q->front;
}

void enqueue(queue_t* q, elem_t e)
{
    if (is_full(q)) {
        printf("꽉참\n");
        return;
    }
    q->data[q->rear++] = e;
}

elem_t dequeue(queue_t* q)
{
    if (is_empty(q)) {
        printf("비었음\n");
        return err_elem;
    }
    return q->data[q->front++];
}

elem_t peek(queue_t* q)
{
    if (is_empty(q)) {
        printf("비었음\n");
        return err_elem;
    }
    return q->data[q->front];
}