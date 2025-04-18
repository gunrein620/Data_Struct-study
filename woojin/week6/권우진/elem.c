#include <stdio.h>
#include "elem.h"
elem_t err_elem = -1;
char output[100];
char* str(elem_t e) {
	sprintf(output, "%4d", e);
	return output;
}