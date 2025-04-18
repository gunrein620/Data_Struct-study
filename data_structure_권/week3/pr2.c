#include <stdio.h>
#include <stdlib.h>

typedef int elem_t;

struct tag
{
    int size;
    elem_t numbers[100];
}typedef arrlist_t;

void run_menu(arrlist_t*);
void input_list(arrlist_t*);
void print_list(arrlist_t*);
void add_list(arrlist_t*, elem_t);
void insert_list(arrlist_t*, int, elem_t);
elem_t delete_list(arrlist_t*, elem_t);
elem_t update_list(arrlist_t*, int, elem_t);
elem_t get_at(arrlist_t* listp, int index);
int len(arrlist_t* listp);
int find(arrlist_t* listp, elem_t e);
void hap(arrlist_t*, arrlist_t*, arrlist_t*);
void kyo(arrlist_t*, arrlist_t*, arrlist_t*);


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

void kyo(arrlist_t* set1, arrlist_t* set2, arrlist_t* result)
{
    result->size = 0;
    for (int i = 0; i < len(set1); i++)
        if (find(result, get_at(set1, i)) == -1)
            add_list(result, get_at(set1, i));
    for (int i = 0; i < len(set2); i++)
        if (find(result, get_at(set2, i)) == -1)
            add_list(result, get_at(set2, i));
}

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