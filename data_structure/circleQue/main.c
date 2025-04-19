#include <stdio.h>
#include "queue.h"

int main() {
    que_t qu;
    init(&qu);

    int option;
    elem_t value;

    while (1) {
        printf("\n옵션 선택 (1: 인큐, 2: 디큐, 3: 큐 출력, -1: 종료): ");
        if (scanf("%d", &option) != 1) {
            // 입력 오류 시 종료
            break;
        }

        if (option == -1) {
            printf("프로그램을 종료합니다.\n");
            break;
        }

        switch (option) {
            case 1:
                printf("삽입할 값 입력: ");
                scanf("%d", &value);
                enque(&qu, value);
                break;

            case 2:
                value = deque(&qu);
                if (value != err_elem) {
                    printf("디큐된 값: %d\n", value);
                }
                break;

            case 3:
                print_que(&qu);
                break;

            default:
                printf("잘못된 옵션입니다. 1, 2, 3 또는 -1을 입력하세요.\n");
                break;
        }
    }

    return 0;
}