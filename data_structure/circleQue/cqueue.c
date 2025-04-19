#include <stdio.h>
#include "queue.h"

void init(que_t *qu){
  qu->front = 0;
  qu->rear = 0;
}
int is_full(que_t *qu){
  return (qu->rear+1)% MAX_SIZE == qu->front;
}

int is_empty(que_t *qu){
  return qu->rear == qu->front; 
}
void enque(que_t *qu,elem_t e){
  if (is_full(qu)) {
    printf("큐가 가득참");
    return;
  }
  qu->str[qu->rear] = e;
  qu->rear = (qu->rear+ 1) % MAX_SIZE;
  }
elem_t deque(que_t *qu) {
  if (is_empty(qu)){
    printf("큐가 비었음");
    return err_elem;
  }
  elem_t temp = qu->str[qu->front];
  qu->front = (qu->front + 1) % MAX_SIZE;
  return temp; 
}
void print_que(que_t *qu) {
    if (is_empty(qu)) {
        printf("큐가 비었음\n");
        return;
    }

    int i = qu->front;
    while (i != qu->rear) {
        printf("%d ", qu->str[i]);
        i = (i + 1) % MAX_SIZE;  // 한 칸 이동하면서 순환 처리
    }
    printf("\n");
}
