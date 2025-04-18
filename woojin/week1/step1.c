#include <stdio.h>
#include <stdlib.h>

void input_list();
void print_list();


int size = 0;
int numbers[100];   //    최대 크기 100으로 배열 선언

void main() 
{
	printf("숫자의 개수를 입력하시오 : ");
	scanf("%d", &size);
	input_list();
	print_list();
	printf("\n안녕히 가세요\n");
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
}