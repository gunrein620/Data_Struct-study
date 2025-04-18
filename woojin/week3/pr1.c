#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

struct tag
{
    int size;
    elem_t numbers[100];
}typedef arrlist_t;

void run_menu(arrlist_t*);
void input_list(arrlist_t*);
void print_list(arrlist_t*);
void add_list(arrlist_t*, elem_t);
void insert_list(arrlist_t*, int, elem_t);
elem_t delete_list(arrlist_t*, elem_t);
elem_t update_list(arrlist_t*, int, elem_t);

int main()
{
    arrlist_t mylist; 
    printf("숫자의 개수를 입력하시오 : ");
    scanf("%d", &mylist.size);
    input_list(&mylist);
    run_menu(&mylist);
    return 0;
}

void run_menu(arrlist_t* listp)
{
    int pos;
    elem_t val;
    int menu = 0;

    while(menu != 5)
    {
        print_list(listp);
        printf("(1) 끝에 값 추가   \n(2) pos번째에 값 추가\n");
        printf("(3) pos번째 삭제   \n(4) pos번째 값 변경   \n(5) 종료                  ");
        printf("메뉴선택 => ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                printf("끝에 추가할 값: ");
                scanf("%d", &val);
                add_list(listp, val);
                break;
            case 2:
                printf("추가할 위치와 값: ");
                scanf("%d %d", &pos, &val);
                insert_list(listp, pos, val);
                break;
            case 3:
                printf("삭제할 위치: ");
                scanf("%d", &pos);
                delete_list(listp, pos);
                break;
            case 4:
                printf("변경할 위치와 값: ");
                scanf("%d %d", &pos, &val);
                update_list(listp, pos, val);
                break;
            case 5:
                printf("\n안녕히 가세요.\n");
                break;
            default:
                printf("유효하지 않은 입력입니다.\n\n");
                break;
        }
    }
}

elem_t get_next()
{
    return rand() % 100;
}

void input_list(arrlist_t* listp)
{
	for (int i = 0; i < listp->size; ++i) 
	{
		listp->numbers[i] = get_next();
	}
}

void print_list(arrlist_t* listp)
{
	for (int i = 0; i < listp->size; ++i) 
	{
		printf("%3d,", listp->numbers[i]);
		if (i % 8 == 7)
			printf("\n");
	}
    printf("\n");
}

void add_list(arrlist_t* listp, elem_t val)
{
    printf("값 %d를 리스트 맨 끝에 추가합니다.\n", val);
    listp->numbers[listp->size++] = val;
}

void insert_list(arrlist_t* listp, int pos, elem_t val)
{
    printf("값 %d를 %d 번째에 삽입합니다.\n", val, pos);
    for (int k = listp->size - 1; k >= pos; k--)
        listp->numbers[k + 1] = listp->numbers[k];
        listp->numbers[pos] = val;
    listp->size++;
}

elem_t delete_list(arrlist_t* listp, int pos)
{
    elem_t result = listp->numbers[pos];
    for (int k = pos; k < listp->size - 1; k++)
        listp->numbers[k] = listp->numbers[k + 1];
    printf("%d 번째 값을 삭제합니다. 값 = %d\n", pos, result);
    listp->size--;
    return result;
}

elem_t update_list(arrlist_t* listp, int pos, elem_t val)
{
    elem_t result = listp->numbers[pos];
    listp->numbers[pos] = val;
    printf("%d 번째 값을 %d로 변경합니다. 이전값 = %d\n", pos, val, result);
    return result;
}