#include <stdio.h>
#define A 0
#define B 1
#define C 2
typedef struct tower {
	char name;
	int plates[10];
	int size;
} pole_t;
int n_plates = 4;
pole_t poles[3] = { 'A', {4, 3, 2, 1}, 4, 'B', {0}, 0, 'C', {0}, 0 };
void init() {
	for (int i = 0; i < n_plates; i++) {
		poles[A].plates[i] = n_plates - i;
	}
	poles[A].size = n_plates;
	poles[B].size = poles[C].size = 0;
}
int tab = 0;
void print_tabs() {
	for (int i = 0; i < tab; i++)
		printf("    ");
}
void print_hanoi() {
	print_tabs();
	for (int i = 0; i < 3; i++) {
		printf("%c [", poles[i].name);
		for (int k = 0; k < poles[i].size; k++)
			printf("%2d", poles[i].plates[k]);
		printf("]\t");
	}
	printf("\n");
}
void move(int n, char from, char to)
{
	poles[from].size--;
	poles[to].plates[poles[to].size++] = n;
	print_hanoi();
}
char* series[10] = { "", "1", "21", "321", "4321", "54321", "654321",
					 "7654321", "87654321", "987654321"};
void hanoi_tower(int n, char from, char tmp, char to)
{
	//print_tabs();
	if (n == 1) move(1, from, to);
	else {
		tab++;
		print_tabs();
		printf("%s   %c     %c    ?  %c    ? \n",
			series[n], from + 'A', tmp + 'A', to + 'A');
		hanoi_tower(n - 1, from, to, tmp);
		print_tabs();
		printf("%d   %c     %c    ? \n",
			n, from + 'A', to + 'A');
		move(n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
		tab--;
	}
	//print_hanoi();
}
int main(void)
{
	printf("         : ");
	scanf("%d", &n_plates);
	init();
	hanoi_tower(n_plates, A, B, C);
	return 0;
}