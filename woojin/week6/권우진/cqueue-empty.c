#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(queue_t* q)
{
	q->front = 0;
	q->rear = 0;
}

int is_full(queue_t* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int is_empty(queue_t* q)
{
	return (q->front == q->rear);
}

void enqueue(queue_t* q, elem_t item)
{
	if (is_full(q)) {
		printf("큐가 포화상태입니다\n");
		return;
	}
	
	q->data[q->rear] = item;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

elem_t dequeue(queue_t* q)
{
	if (is_empty(q)) {
		printf("큐가 비어있습니다\n");
		return err_elem;
	}
	elem_t tmp = q->data[q->front];
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return tmp;
}

elem_t peek(queue_t* q)
{
	if (is_empty(q)) {
		printf("큐가 비어있습니다\n");
		return err_elem;
	}
	return q->data[q->front];
}

// 원형큐 출력 함수
void print_queue(queue_t* q)
{
	printf("[");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (q->front <= q->rear) {
			if (i >= q->front && i < q->rear) {
				printf("%3d", q->data[i]);
			} else {
				printf("  --  ");
			}
		} else {
			if (i >= q->front || i < q->rear) {
				printf("%3d", q->data[i]);
			} else {
				printf("  --  ");
			}
		}
	}
	printf(" ]");
}
