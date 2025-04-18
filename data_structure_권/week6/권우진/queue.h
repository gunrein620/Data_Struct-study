#pragma once
#include "elem.h"
#define MAX_QUEUE_SIZE 20

typedef struct q { // 큐 타입
	elem_t  data[MAX_QUEUE_SIZE];
	int  front, rear;
} queue_t;

// 공백 상태 검출 함수
void init_queue(queue_t* q);

// 공백 상태 검출 함수
int is_empty(queue_t* q);

// 포화 상태 검출 함수
int is_full(queue_t* q);

// 원형큐 출력 함수
void print_queue(queue_t* q);

// 삽입 함수
void enqueue(queue_t* q, elem_t e);

// 삭제 함수
elem_t dequeue(queue_t* q);

// 삭제 함수
elem_t peek(queue_t* q);