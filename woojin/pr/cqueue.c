#include <stdio.h>
#include "cqueue.h"

void init(cqueue_t* q)
{
    q->front = 0;
    q->rear = 0;
}

int is_full(cqueue_t* q)
{
    return (q->rear + 1) % MAX_SIZE == q->front;
}

int is_empty(cqueue_t* q)
{
    return q->rear == q->front;
}

void enqueue(cqueue_t* q, elem_t e)
{
    if (is_full(q)) {
        printf("큐가 꽉 찼습니다.\n");
        return;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

elem_t dequeue(cqueue_t* q, elem_t e)
{
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return err_elem;
    }
    elem_t tmp = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return tmp;
}

elem_t peek(cqueue_t* q)
{
    if (is_empty(q)) {
        printf("큐가 비었습니다.\n");
        return err_elem;
    }
    return q->data[q->front];
}

void print_cqueue(cqueue_t* q)
{
    printf("[ ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (q->front <= q->rear) {
            if (i >= q->front && i < q->rear)
                printf("%2d", q->data[i]);
            else
                printf("  --");
        } else {
            if (i >= q->front || i < q->rear)
                printf("%2d", q->data[i]);
            else
                printf("  --");
        }
    }
    printf(" ]\n");
}