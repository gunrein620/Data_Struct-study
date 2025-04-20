#include <stdio.h>
#include "queue.h"

void init(queue_t* q)
{
    q->rear = 0;
    q->front = 0;
}

int is_full(queue_t* q)
{
    return (q->rear + 1) % MAX_SIZE;
}

int is_empty(queue_t* q)
{
    return q->rear == q->front;
}

void enqueue(queue_t* q, elem_t e)
{
    if (is_full(q)) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

elem_t dequeue(queue_t* q)
{
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return err_elem;
    }
    elem_t tmp = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return tmp;
}

elem_t peek(queue_t* q)
{
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return err_elem;
    }
    q->data[q->front];
}
