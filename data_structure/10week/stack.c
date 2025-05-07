#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void init(stack_t* sp) {
	sp->top = 0;
}
void push(stack_t* sp, elem_t e) {
	if (is_full(sp)) {
		printf("���� Ǯ\n");
		return;
	}
	sp->data[sp->top++] = e;   // �� ����
}
int is_full(stack_t* sp) {
	return (sp->top == MAX_STACK_SIZE);
}
elem_t pop(stack_t* sp) {
	if (is_empty(sp)) {
		printf("스택 empty\n");
		return -1;  // ���� ��
	}
	return sp->data[--sp->top];  // �� ����
}
elem_t peek(stack_t* sp) {
	if (is_empty(sp)) {
		printf("스택 empty\n");
		return NULL;  // ���� ��
	}
	return sp->data[sp->top - 1];  // �� ����
}
int is_empty(stack_t* sp) {
	if (sp->top == 0)
		return 1;
	return 0;
}
void print_stack(stack_t* s) {
	printf("[");
	for (int i = 0; i < s->top; i++)
		;// printf("%4d", s->data[i]);
	printf("]\n");
}