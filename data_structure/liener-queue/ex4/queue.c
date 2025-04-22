#include <stdio.h>
#include "queue.h"


void init(que_q *qu){
  qu->front = 0;
  qu->rear = 0;
}
int is_full(que_q *qu){
  return qu->rear == MAX_SIZE;
}
int is_empty(que_q *qu){
  return qu->front == qu->rear;
}
void enque(que_q * qu, elem_t e){
  if(is_full(qu)){
    printf("가득참");
    return;
  }
  qu->data[qu->rear++] = e;
}
elem_t deque(que_q *qu){
  if(is_empty(qu)){
    printf("큐가 빔");
    return err_elem;
  }
  return qu->data[qu->front++];
}
elem_t peek(que_q *qu){
  if(is_empty(qu)){
    printf("큐가 빔");
    return err_elem;
  }
  return qu->data[qu->front];
}

