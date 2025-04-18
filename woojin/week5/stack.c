#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void push(stack_t* s, elem_t e) {
	if (is_full(s)) {
		fprintf(stderr, "스택이 꽉 찼습니다.\n");
		return;
	}
	s->data[(s->top)++] = e;
}
elem_t pop(stack_t* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택이 비었습니다.\n");
		return err_elem;
	}
	return s->data[--(s->top)];
}

int is_empty(stack_t* s) {
	return (s->top == 0);
}

int is_full(stack_t* s) {
	return (s->top == MAX_STACK_SIZE);
}

void init_stack(stack_t* s) {
	s->top = 0;
}

void print_stack(stack_t* s) {
	for (int i = 0; i < s->top; i++)
		printf("%4s", str(s->data[i]));
	for (int i = s->top; i < MAX_STACK_SIZE; i++)
		printf("%4s", " ");
	printf("\n");
}