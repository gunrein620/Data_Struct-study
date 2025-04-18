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
void enqueue(que_t *qu,elem_t e){
  if (is_full(qu)) {
    printf("큐가 가득참");
    return;
  }
  qu->str[qu->rear] = e;
  qu->rear = (qu->rear+ 1) % MAX_SIZE;
  }
elem_t dequeue(que_t *qu) {
  if (is_empty(qu)){
    printf("큐가 비었음");
    return err_elem;
  }
  elem_t temp = qu->str[qu->front];
  qu->front = (qu->front + 1) % MAX_SIZE;
  return temp; 
}
