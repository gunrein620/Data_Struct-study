#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define MAZE_SIZE 100
#define WALL '#'
#define ROAD '.'
#define GOAL 'G'
#define VISIT '0'

void check_next(stack_t* sp, elem_t here);
int input_maze(char(*maze)[100]);
void push_loc(stack_t* sp, int r, int c);
void print_maze();

elem_t entry = { 0, 0 };
int maze_size;
char maze[MAZE_SIZE][MAZE_SIZE] = { '\0' };

int main() 
{
	stack_t mystack;
	init(&mystack);
	maze_size = input_maze(maze);

	elem_t here = entry;
	
	char yn[5];

	while (1)
	{	
		printf("### here = %s\n", str(here));
		if (maze[here.r][here.c] == GOAL)
			break;
		if (maze[here.r][here.c] == ROAD)
			maze[here.r][here.c] = VISIT;
		
		print_maze();
        check_next(&mystack, here);

        here = pop(&mystack);
		
        printf("계속 진행하시겠습니까? (y/n): ");
        scanf("%s", yn);
        if (yn[0] == 'n' || yn[0] == 'N') {
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
	}
	printf("성공\n");	
}

int input_maze(char(*maze)[100])
{
	int sz;
	
	printf("미로 크기: ");
	scanf("%d", &sz);
	for (int i = 0; i < sz; i++)
		scanf("%s", maze[i]);
	getchar();
	return sz;
}

void check_next(stack_t* sp, elem_t here)
{
	int r = here.r;
    int c = here.c;
    push_loc(sp, r - 1, c);
    push_loc(sp, r, c - 1);
    push_loc(sp, r + 1, c);
    push_loc(sp, r, c + 1);
}

void push_loc(stack_t* sp, int r, int c)
{
	if (r < 0 || c < 0) return;
    if (r >= maze_size || c >= maze_size) return;
    if (maze[r][c] == WALL || maze[r][c] == VISIT) return;

    elem_t tmp = {r, c};
    push(sp, tmp);
}

void print_maze()
{
	for (int i = 0; i < maze_size; i++)
		printf("%s\n", maze[i]);
	printf("\n");
}