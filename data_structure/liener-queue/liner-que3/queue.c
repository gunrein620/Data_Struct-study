#include <stdio.h>
#include "queue.h"

void init(que *qu){
  qu->front = 0;
  qu->rear = 0;
}
int is_full(que *qu){
  return qu->rear == MAX_SIZE;
}
int is_empty(que *qu){
  return qu->front == qu->rear;
}
void enque(que *qu, elem_t e){
  if (is_full(qu)){
    printf("큐 포화");
    return;
  }
  e = qu->data[qu->rear++];
}
elem_t deque(que *qu){
  if (is_empty(qu)){
    printf("큐가 비었음");
    return err_elem;
  }
  return qu->data[qu->front++];
}
elem_t peek(que *qu){
    if (is_empty(qu)){
    printf("큐가 비었음");
    return err_elem;
  }
  return qu->data[qu->front];
}
void print(que *qu);

