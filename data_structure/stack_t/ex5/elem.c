#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elem.h"

err_elem = {-1,-1};
char buf[10];
char* str(elemt_t e){
  snprintf(buf,sizeof(buf),"(%d,%d)",e.r , e.c);
  return buf;
}