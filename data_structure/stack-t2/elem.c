#include <stdio.h>
#include "elem.h"

elem_t err_elem = {-1,-1};
char buf[20];

char *str(elem_t e){
    snprintf(buf,sizeof(buf),"(%d, %d)", e.r, e.r);
    return buf;
}