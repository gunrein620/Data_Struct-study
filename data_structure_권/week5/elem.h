#pragma once
struct tag {
	int r;
	int c;
};
typedef struct tag elem_t;
extern elem_t err_elem;
char* str(elem_t e);