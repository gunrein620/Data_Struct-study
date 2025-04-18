#include <stdio.h>
#include <stdlib.h>
#include "arrlist.h"

elem_t get_next()
{
    return rand() % 10;
}

void input_list(arrlist_t* listp)
{
	for (int i = 0; i < listp->size; ++i) 
	{
		listp->numbers[i] = get_next();
	}
}

void print_list(arrlist_t* listp)
{
	for (int i = 0; i < listp->size; ++i) 
	{
		printf("%3d,", listp->numbers[i]);
		if (i % 8 == 7)
			printf("\n");
	}
    printf("\n");
}

void hap(arrlist_t* set1, arrlist_t* set2, arrlist_t* result)
{
    result->size = 0;
    for (int i = 0; i < len(set1); i++)
        if (find(result, get_at(set1, i)) == -1)
            add_list(result, get_at(set1, i));
    for (int i = 0; i < len(set2); i++)
        if (find(result, get_at(set2, i)) == -1)
            add_list(result, get_at(set2, i));
}

int main()
{
    arrlist_t list1, list2;
    list1.size = 5;
    list2.size = 5;
    input_list(&list1);
    input_list(&list2);
    print_list(&list1);
    print_list(&list2);
    arrlist_t result;
    hap(&list1, &list2, &result);
    print_list(&result);
    return 0;
}