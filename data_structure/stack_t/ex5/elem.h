#pragma once 

struct tag
{
  int r,c;
};
typedef struct tag elemt_t;
extern elemt_t err_elem;
char* str(elemt_t);
