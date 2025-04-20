#include <stdio.h>
#include "cqueue.h"

void init(cqueue_t* q)
{
    q->front = q->rear = 0;
}

int is_full(cqueue_t* q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int is_empty(cqueue_t* q)
{
    return q->front == q->rear;
}

void enqueue(cqueue_t* q, elem_t e)
{
    if (is_full(q)) {
        printf("꽉참\n");
        return;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

elem_t dequeue(cqueue_t* q)
{
    if (is_empty(q)) {
        printf("비었음\n");
        return err_elem;
    }
    elem_t tmp = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return tmp;
}

elem_t peek(cqueue_t* q)
{
    if (is_empty(q)) {
        printf("비었음\n");
        return err_elem;
    }
    return q->data[q->front];
}