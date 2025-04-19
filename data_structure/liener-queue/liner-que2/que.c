#include <stdio.h>
#include "queue.h"

void init(qu_t *qu){
  qu->front = 0;
  qu->rear = 0;
}

int is_full(qu_t *qu){
  return qu->rear == MAX_SIZE;
}

int is_empty(qu_t *qu){
  return qu->front == qu->rear;
}

void enque(qu_t *qu,elem_t e){
  if (is_full(qu)){
    printf("큐가 가득참");
    return;
  }
  qu->data[qu->rear] = e;
    qu->rear++;
}

elem_t deque(qu_t *qu){
  if (is_empty(qu))
  {
    printf("큐가 비었음");
    return err_elem;
  }
  elem_t temp = qu->data[qu->front];
  qu->front++;
  return temp;
}

void print_que(qu_t *qu){
  for (int i = qu->front; i < qu->rear; i++)
  {
    printf("%d ",qu->data[i]);
  }
  printf("\n");
}
  

