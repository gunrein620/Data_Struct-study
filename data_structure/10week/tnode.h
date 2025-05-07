#pragma once
struct tnode {
	int val;
	char op;
	struct tnode* left;
	struct tnode* right;
};
typedef struct tnode tnode_t;