#include <stdio.h>
#include "queue.h"

void init(queue_t* q)
{
    q->front = 0;
    q->rear = 0;
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
        printf("큐가 꽉 찼습니다.\n");
        return;
    }
    q->data[q->rear++] = e;
}

elem_t dequeue(queue_t* q)
{
    if (is_empty(q)) {
        printf("큐가 비어있습니다.\n");
        return err_elem;
    }
    return q->data[q->front++];
}

elem_t peek(queue_t* q)
{
    if (is_empty(q)) {
        printf("큐가 비어있습니다.\n");
        return err_elem;
    }
    return q->data[q->front];
}

void print_queue(queue_t* q)
{
    printf("[ ");
    for (int i = 0; i < MAX_SIZE; i++) {
        if (i >= q->front && i < q->rear)
            printf("%2d", q->data[i]);
        else
            printf("  --");
    }
    printf(" ]\n");
}