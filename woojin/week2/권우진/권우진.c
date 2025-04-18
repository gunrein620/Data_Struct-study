#include <stdio.h>
#include <math.h>

struct tag
{
    int x;
    int y;
} typedef elem_t;

void run_menu();
elem_t get_next();
void print_list();
char* str(elem_t);
elem_t move_point(int, elem_t);
elem_t add_point(int, int);
float get_distance(int, int);
void exchange(int, int);

int size = 4;
elem_t values[100] = {{11, 11}, {22, 22}, {33, 33}, {44, 44}};

int main()
{
    run_menu();
    return 0;
}

void run_menu()
{
    int pos, other;
    elem_t val;
    int menu = 0;

    while(menu != 5)
    {
        print_list();
        printf("(1) 좌표 이동   \n(2) 두 개 좌표 더하기\n");
        printf("(3) 두개 좌표 거리 구하기   \n(4) 두 개 좌표 바꾸기   \n(5) 종료                  ");
        printf("메뉴선택 => ");
        scanf("%d", &menu);

        switch (menu)
        {
            case 1:
                printf("이동할 좌표 번호와 이동 값 dx, dy를 입력하세요.. ");
                scanf("%d", &pos);
                val = move_point(pos, get_next());
                printf("이동한 좌표: %s\n", str(val));
                break;
            case 2:
                printf("더할 두 개의 좌표 번호를 넣으세요.. ");
                scanf("%d %d", &pos, &other);
                val = add_point(pos, other);
                printf("더한 결과 좌표: %s\n", str(val));
                break;
            case 3:
                printf("거리를 구할 두 개의 좌표 번호를 넣으세요..");
                scanf("%d %d", &pos, &other);
                float distance = get_distance(pos, other);
                printf("두 좌표 간 거리: %5.3f\n", distance);
                break;
            case 4:
                printf("수정할 위치와 값을 입력하세요..");
                scanf("%d %d", &pos, &other);
                exchange(pos, other);
                break;
            case 5:
                printf("\n안녕히 가세요.\n");
                break;
            default:
                printf("유효하지 않은 입력입니다.\n\n");
                break;
        }
        printf("\n");
    }
}

char outbuf[30];
char* str(elem_t val)
{
    sprintf(outbuf, "(%d, %d)", val.x, val.y);
    return outbuf;
}

elem_t get_next()
{
    elem_t val;
    scanf("%d %d", &val.x, &val.y);
    return val;
}

elem_t move_point(int pos, elem_t val)
{
    values[pos].x += val.x;
    values[pos].y += val.y;
    return values[pos];
}

elem_t add_point(int pos, int other)
{
    elem_t added = {values[pos].x + values[other].x, values[pos].y + values[other].y};
    return added;
}

float get_distance(int pos, int other)
{
    int x = values[pos].x - values[other].x;
    int y = values[pos].y - values[other].y;
    return sqrt(pow(x, 2) + pow(y, 2));
}

void exchange(int pos, int other)
{
    elem_t tmp = values[pos];
    values[pos] = values[other];
    values[other] = tmp;
}

void print_list()
{
	for (int i = 0; i < size; ++i) 
	{
		printf("%s,", str(values[i]));
		if (i % 8 == 7)
			printf("\n");
	}
    printf("\n");
}