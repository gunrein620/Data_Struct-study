#include <stdio.h>
#include <stdlib.h>
#include "arrlist.h"

elem_t get_at(arrlist_t* listp, int indx) {
    return listp->numbers[indx];
}

int len(arrlist_t* listp) {
    return listp->size;
}
   
int find(arrlist_t* listp, elem_t e) {
    for (int i = 0; i < listp->size; i++) {
        if (listp->numbers[i] == e)
            return i;
    }
    return -1;
}

void add_list(arrlist_t* listp, elem_t val)
{
    printf("값 %d를 리스트 맨 끝에 추가합니다.\n", val);
    listp->numbers[listp->size++] = val;
}

void insert_list(arrlist_t* listp, int pos, elem_t val)
{
    printf("값 %d를 %d 번째에 삽입합니다.\n", val, pos);
    for (int k = listp->size - 1; k >= pos; k--)
        listp->numbers[k + 1] = listp->numbers[k];
        listp->numbers[pos] = val;
    listp->size++;
}

elem_t delete_list(arrlist_t* listp, int pos)
{
    elem_t result = listp->numbers[pos];
    for (int k = pos; k < listp->size - 1; k++)
        listp->numbers[k] = listp->numbers[k + 1];
    printf("%d 번째 값을 삭제합니다. 값 = %d\n", pos, result);
    listp->size--;
    return result;
}

elem_t update_list(arrlist_t* listp, int pos, elem_t val)
{
    elem_t result = listp->numbers[pos];
    listp->numbers[pos] = val;
    printf("%d 번째 값을 %d로 변경합니다. 이전값 = %d\n", pos, val, result);
    return result;
}