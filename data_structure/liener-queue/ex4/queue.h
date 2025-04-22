#include "elem.h";
#define MAX_SIZE 10

typedef struct queue
{
  elem_t data[MAX_SIZE];
  int front, rear;
}que_q;

// i f e edp

void init(que_q *qu);
int is_full(que_q *qu);
int is_empty(que_q *qu);
void enque(que_q * qu, elem_t e);
elem_t deque(que_q *qu);
elem_t peek(que_q *qu);

