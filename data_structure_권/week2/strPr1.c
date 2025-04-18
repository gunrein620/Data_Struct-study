#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_menu();
char* get_next();
void input_list();
void print_list();
void add_list(char*);
void insert_list(int, char*);
char* delete_list(int);
char* update_list(int, char*);

int size = 0;
char* values[100];

int main()
{
    printf("문자열의 개수를 입력하시오 : ");
    scanf("%d", &size);
    printf("%d개의 문자열을 입력하시오 : ", size);
    input_list();
    run_menu();
    
    return 0;
}

void run_menu()
{
    int pos;
    char* val;
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
                add_list(get_next());
                break;
            case 2:
                printf("추가할 위치와 값: ");
                scanf("%d", &pos);
                insert_list(pos, get_next());
                break;
            case 3:
                printf("삭제할 위치: ");
                scanf("%d", &pos);
                val = delete_list(pos);
                free(val);
                break;
            case 4:
                printf("변경할 위치와 값: ");
                scanf("%d", &pos);
                update_list(pos, get_next());
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

char* get_next()
{
    char buf[20];
    scanf("%s", buf);
    char* chptr = (char*)malloc((strlen(buf) + 1) * sizeof(char));
    strcpy(chptr, buf);
    return chptr;
}

void input_list()
{
    for (int i = 0; i < size; ++i) 
        values[i] = get_next();
}

void print_list()
{
	for (int i = 0; i < size; ++i) 
	{
		printf("%s,", values[i]);
		if (i % 8 == 7)
			printf("\n");
	}
    printf("\n");
}

void add_list(char* val)
{
    printf("값 %s를 리스트 맨 끝에 추가합니다.\n", val);
    values[size++] = val;
}

void insert_list(int pos, char* val)
{
    printf("값 %s를 %d 번째에 삽입합니다.\n", val, pos);
    for (int k = size - 1; k >= pos; k--)
        values[k + 1] = values[k];
    values[pos] = val;
    size++;
}

char* delete_list(int pos)
{
    char* result = values[pos];
    for (int k = pos; k < size - 1; k++)
        values[k] = values[k + 1];
    printf("%d 번째 값을 삭제합니다. 값 = %s\n", pos, result);
    size--;
    return result;
}

char* update_list(int pos, char* val)
{
    char* result = values[pos];
    values[pos] = val;
    printf("%d 번째 값을 %s로 변경합니다. 이전값 = %s\n", pos, val, result);
    return result;
}

void free_list()
{
    for (int i = 0; i < size; i++)
        free(values[i]);
}