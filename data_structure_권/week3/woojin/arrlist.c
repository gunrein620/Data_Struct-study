#include<stdio.h>
#include "arrlist.h"

void print_list(arrlist_t* listp)
{
    for (int i = 0; i < listp->size; i++)
        printf(" %d,", listp->numbers[i]);
}

void append(arrlist_t* left, arrlist_t* right)
{
    for (int i = 0; i < right->size; i++)
        add_list(left, right->numbers[i]);
}

void add(arrlist_t* result)
{
    for (int i = 0; i < result->size; i++)
        for (int j = i + 1; j < result->size; j++)
            if (result->numbers[i] == result->numbers[j])
                delete_list(result, j);
}

void common(arrlist_t* left, arrlist_t* right, arrlist_t* result)
{
    for (int i = 0; i < left->size; i++)
    {
        int flag = find(right, left->numbers[i]);
        if (flag != -1)
            result->numbers[result->size++] = left->numbers[i];
    }
}

void delete_list(arrlist_t* left, int index)
{
    for (int i = index; i < left->size - 1; i++)
        left->numbers[i] = left->numbers[i + 1];
    left->size--;
}

int sum_list(arrlist_t* left)
{
    int sum = 0;
    for (int i = 0; i < left->size; i++)
    {
        sum += left->numbers[i];
    }
    return sum;
}

void reverse_list(arrlist_t* left)
{
    for (int i = left->size - 1; i >= 0; i--)
        printf(" %d,", left->numbers[i]);
}

int len(arrlist_t* left)
{
    return left->size;
}

void add_list(arrlist_t* listp, elem_t e)
{
    listp->numbers[listp->size++] = e;
}

int find(arrlist_t* listp, elem_t e)
{
    for (int i = 0; i < listp->size; i++) {
        if (listp->numbers[i] == e)
            return i;
    }
    return -1;
}