#include <stdio.h>
#include "cque.h"

void init(cque_cq *cq){
  cq->front = 0;
  cq->rear = 0;
}
int is_full(cque_cq *cq){
  return (cq->rear + 1) % MAX_SIZE == cq->front;
}
int is_empty(cque_cq *cq){
  return cq->front == cq->rear;
}
void enque(cque_cq *cq, elem_t e){
  if (is_full(cq)){
    printf("원형큐 포화");
    return;
  }
  cq->data[cq->rear] = e;
  cq->rear = (cq->rear + 1) % MAX_SIZE;
}
elem_t deque(cque_cq *cq){
  if(is_empty(cq)){
    printf("원형큐 빔");
    return err_elem;
    }
  elem_t temp = cq->data[cq->front];
  cq->front = (cq->front +1) % MAX_SIZE;
  return temp;
}

elem_t peek(cque_cq *cq){
  if(is_empty(cq)){
    printf("원형큐 빔");
    return err_elem;
    }
  return cq->data[cq->front];
}