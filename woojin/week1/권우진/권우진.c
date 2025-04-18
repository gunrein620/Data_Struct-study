#include <stdio.h>
#include <stdlib.h>

void run_menu();
void input_list();
void print_list();
void add_list(int);
void insert_list(int, int);
int delete_list(int);
int update_list(int, int);

int size = 0;
int numbers[100];   //    최대 크기 100으로 배열 선언

int main()
{
    printf("숫자의 개수를 입력하시오 : ");
    scanf("%d", &size);
    input_list();
    run_menu();
    
    return 0;
}

void run_menu()
{
    int pos, val;
    int menu = 0;

    while(menu != 5)
    {
        print_list();
        printf("(1) 끝에 값 추가   \n(2) pos번째에 값 추가\n");
        printf("(3) pos번째 삭제   \n(4) pos번째 값 변경   \n(5) 종료                  ");
        printf("메뉴선택 => ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                printf("끝에 추가할 값: ");
                scanf("%d", &val);
                add_list(val);
                break;
            case 2:
                printf("추가할 위치와 값: ");
                scanf("%d %d", &pos, &val);
                insert_list(pos, val);
                break;
            case 3:
                printf("삭제할 위치: ");
                scanf("%d", &pos);
                delete_list(pos);
                break;
            case 4:
                printf("변경할 위치와 값: ");
                scanf("%d %d", &pos, &val);
                update_list(pos, val);
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

void input_list()
{
	printf("%d개의 정수를 입력하시오: ", size);
	for (int i = 0; i < size; ++i) 
	{
		numbers[i] = rand() % 100;
	}
}

void print_list()
{
	for (int i = 0; i < size; ++i) 
	{
		printf("%3d,", numbers[i]);
		if (i % 8 == 7)
			printf("\n");
	}
    printf("\n");
}

void add_list(int val)
{
    printf("값 %d를 리스트 맨 끝에 추가합니다.\n", val);
    numbers[size++] = val;
}

void insert_list(int pos, int val)
{
    printf("값 %d를 %d 번째에 삽입합니다.\n", val, pos);
    for (int k = size - 1; k >= pos; k--)
        numbers[k + 1] = numbers[k];
    numbers[pos] = val;
    size++;
}

int delete_list(int pos)
{
    int result = numbers[pos];
    for (int k = pos; k < size - 1; k++)
        numbers[k] = numbers[k + 1];
    printf("%d 번째 값을 삭제합니다. 값 = %d\n", pos, result);
    size--;
    return result;
}

int update_list(int pos, int val)
{
    int result = numbers[pos];
    numbers[pos] = val;
    printf("%d 번째 값을 %d로 변경합니다. 이전값 = %d\n", pos, val, result);
    return result;
}