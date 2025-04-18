#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrlist.h"

arrlist_t alist = { 5 };
arrlist_t blist = { 5 };
arrlist_t clist = { 5 };
arrlist_t result = { 0 };

void run_menu();
void input_list(arrlist_t*);

void main() 
{
    input_list(&alist);
    input_list(&blist);
    input_list(&clist);
    run_menu();
    printf("\n안녕히 가세요\n");
}

arrlist_t* get(char ch)
{
    switch (ch)
    {
    case 'a':
        return &alist;
    case 'b':
        return &blist;
    case 'c':
        return &clist;
    default:
        return NULL;
    }
}

void input_list(arrlist_t* listp)
{
    for (int i = 0; i < listp->size; i++)
    {
        elem_t num = rand() % 100;
        listp->numbers[i] = num;
    }
}

void run_menu() 
{
    int index;
    elem_t val;
    char menu[10], name[5];
    arrlist_t* left, * right;

    while (1) 
    {
        printf("\na = ["); print_list(&alist);
        printf("]\nb = ["); print_list(&blist);
        printf("]\nc = ["); print_list(&clist);
        printf("]\nappend a b : 리스트 a의 뒤에 b 값을 모두 덧붙인다\n");
        printf("add a b : 두 리스트의 합집합을 출력\n");
        printf("common a b : 두 리스트의 교집합을 출력\n");
        printf("del a 3 : 리스트 a의 3번째 요소를 삭제\n");
        printf("avg a : 리스트 a의 평균을 출력\n");
        printf("reverse a : 리스트를 뒤집어서 출력\n");
        printf("명령(끝내려면 end) => ");
        scanf("%s", &menu);
        scanf("%s", &name);
        left = get(name[0]);  // 첫번째 이름의 리스트를 left로
        if (strcmp(menu, "append") == 0) 
        {
            scanf("%s", &name); right = get(name[0]);
            append(left, right);
            print_list(left);
        }
        else if (strcmp(menu, "add") == 0) 
        {
            result.size = 0;
            scanf("%s", &name); right = get(name[0]);
            append(&result, left);
            append(&result, right);
            add(&result);
            print_list(&result);
        }
        else if (strcmp(menu, "common") == 0) 
        {
            result.size = 0;
            scanf("%s", &name); right = get(name[0]);
            common(left, right, &result);
            print_list(&result);
        }
        else if (strcmp(menu, "del") == 0) 
        {
            scanf("%d", &index);  // 번호 입력
            delete_list(left, index);
            print_list(left);
        }
        else if (strcmp(menu, "avg") == 0) 
        {
            double avg = sum_list(left) * 1.0 / (len(left));
            printf("평균 = %5.3f\n", avg);
        }
        else if (strcmp(menu, "reverse") == 0)
        {
            reverse_list(left);
        }
        else if (strcmp(menu, "end") == 0) 
        {
            break;
        }
        else 
        {
            char line[100];
            gets(line);
            continue;
        }
        printf("\n");
    }
}