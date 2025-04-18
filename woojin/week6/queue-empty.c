#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// 큐 초기화 함수
void init_queue(queue_t* q)
{
	q->front = 0;
	q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(queue_t* q)
{
	return (q->front == q->rear);
}

int is_full(queue_t* q)
{
	return (q->rear >= MAX_QUEUE_SIZE);
}

void enqueue(queue_t* q, elem_t item)
{
	if (is_full(q)) {
		printf("큐가 포화상태입니다\n");
		return;
	}
	q->data[q->rear++] = item;
}

elem_t dequeue(queue_t* q)
{
	if (is_empty(q)) {
		printf("큐가 비어있습니다\n");
		return err_elem;
	}
	return q->data[q->front++];
}

elem_t peek(queue_t* q)
{
	if (is_empty(q)) {
		printf("큐가 비어있습니다\n");
		return err_elem;
	}
	return q->data[q->front];
}

void print_queue(queue_t* q)
{
	printf("[");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i >= q->front && i < q->rear)
			printf("%s", str(q->data[i]));
		else printf("  --");
	}
	printf("]");
}
