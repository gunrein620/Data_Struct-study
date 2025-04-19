#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

// ==================
// 여기서 돌아가는거 구현해보기 아직 미완! 
//===================
int main() {
  char buf;
  int input;

que_t qu;
init(&qu);

printf("아무키나 누르면 종료\n");
  while (1)
  {
    printf("인큐: + | 디큐: -   입력하세요: ");
    scanf("%c", &buf);
    getchar();
    if (buf == '+') {
      printf("인큐할 숫자: ");
      scanf("%d",&input);
      getchar();
      enqueue(&qu, input);
    }
    else if (buf == '-')
    {
      printf("디큐된 숫자:");
      elem_t de = dequeue(&qu);
      printf("%d\n",de);
    }
    else{ 
      printf("프로그램을 종료합니다.");
      return 0;
    }
  }
  printf("\n");
}