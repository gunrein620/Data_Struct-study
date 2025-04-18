#include <stdio.h>
#include "queue.h"

void init(que_t *qu){
  qu->front = 0;
  qu->rear = 0;
}
int is_full(que_t *qu){
  return qu->rear == MAX_SIZE; 
}
int is_empty(que_t *qu){
  return qu->front == qu->rear;
}
void enqueue(que_t *qu,elem_t e){
    if (is_full(qu)){
      printf("큐가 가득참");
      return;
    }
    qu->str[qu->rear++] = e;
}
elem_t dequeue(que_t *qu){
    if (is_empty(qu)) {
      printf("큐가 비었음");
      return err_elem;
    }
    return qu->str[qu->front++];
}
elem_t peek(que_t*qu){
  if (is_empty(qu)){
    printf("큐빔");
    return err_elem;
  }
  return qu->str[qu->front];
}