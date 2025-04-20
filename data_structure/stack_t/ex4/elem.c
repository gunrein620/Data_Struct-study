#include <stdio.h>
#include "elem.h"
#define SIZE 10
char buf[SIZE];

elem_t err_elem = {-1,-1};

char *str(elem_t e){
  snprintf(buf,sizeof(buf),"(%d,%d)",e.r,e.c);
  return buf;
}



