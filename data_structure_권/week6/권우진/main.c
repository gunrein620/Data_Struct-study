#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
#define CAPA 14

void add_waits(queue_t*);
void board_shuttle(queue_t*);

void main() {
    queue_t waitline;
    init_queue(&waitline);
    int shuttle_num = 0;
    char out[10];
    
    while (shuttle_num < 20) {
        add_waits(&waitline);
        if (is_empty(&waitline)) break;
        print_queue(&waitline);
        printf("\n\n[%2d] 탑승 ", shuttle_num);
        board_shuttle(&waitline);
        shuttle_num++;
        gets(out);
    }
}

void add_waits(queue_t* q) {
    printf("도착 [");
    for (int i = 0; i < rand() % 8; i++) {
        if (is_full(q)) {
            printf("스택풀\n");
            break;
        }
        int n = rand() % 10 + 1;
        printf("%2d ", n);
        enqueue(q, n);
    }
    printf("]\n");
}

void board_shuttle(queue_t* q) {
    int sum = 0;
    int t = 0;
    printf("[");
    while (1)
    {
        if (is_empty(q)) break;

        elem_t tmp = peek(q);
        sum += tmp;
        if (sum > CAPA) {
            sum -= tmp;
            break;
        } else {
            printf("%2d ", tmp);
            dequeue(q);
        }
    }
    printf("] (%d명 탑승)\n", sum);
}