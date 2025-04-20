#include <stdio.h>
#include "queue.h"

void init(queue_t* q)
{
    q->rear = 0;
    q->front = 0;
}

int is_full(queue_t* q)
{
    return q->rear == MAX_SIZE;
}

int is_empty(queue_t* q)
{
    return q->front == q->rear;
}

void enqueue(queue_t* q, elem_t e)
{
    if (is_full(q)) {
        printf("큐가 가득 찼습니다.\n");
        return;
    }
    q->data[q->rear++] = e;
}

elem_t dequeue(queue_t* q)
{
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return err_elem;
    }
    return q->data[q->front++];
}

elem_t peek(queue_t* q)
{
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return err_elem;
    }
    return q->data[q->front];
}