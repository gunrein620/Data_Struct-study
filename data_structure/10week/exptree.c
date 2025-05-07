#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int evaluate(tnode_t* root)
{
	if (root == NULL) { root->val = 0; return 0; }
	if (root->left == NULL && root->right == NULL) 
		return root->val;
	int val1 = evaluate(root->left);
	int val2 = evaluate(root->right);
	//printf("%d %c %d\n", val1, root->op, val2);
	switch (root->op) {
	case '+': root->val = val1 + val2; break;
	case '-': root->val = val1 - val2; break;
	case '*': root->val = val1 * val2; break;
	case '/': root->val = val1 / val2; break;
	}
	return root->val;
}

int tab = 0;
void print_tab() {
	for (int i = 0; i < tab; i++)
		printf("   ");
}
void print_tree(tnode_t* root)
{
	print_tab();
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) {
		printf(" % d\n", root->val);
		return;
	}
	printf("%c (%d)\n", root->op, root->val);
	tab++;
	print_tree(root->left);
	print_tree(root->right);
	tab--;
}
tnode_t* new_node(char ch) {
	tnode_t* node = (tnode_t*)malloc(sizeof(tnode_t));
	node->left = node->right = NULL;
	if (isdigit(ch)) {
		node->val = ch - '0';
		return node;
	}
	node->op = ch;
	node->val = 0;
	return node;
}
tnode_t* exp_tree(char* line) {
	stack_t s; init(&s);
	tnode_t* node;
	for (int i = 0; i < strlen(line); i++) {
		char ch = line[i];
		if (isdigit(ch)) {
			push(&s, new_node(ch));
		}
		else {
			node = new_node(ch);
			node->right = pop(&s);
			node->left = pop(&s);
			push(&s, node);
		}
	}
	return pop(&s);
}
void main() {
	char line[100];
	scanf("%s", line);
	tnode_t* root = exp_tree(line);
	evaluate(root);
	print_tree(root);
}