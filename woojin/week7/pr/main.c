#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
elem_t err_elem = -9999;
elem_t get(node_t* hdr, int index);
node_t* get_node(node_t* hdr, int index);

int index_of(node_t* hdr, elem_t e);
void increase_all_even(node_t* hdr);
node_t* reverse_list(node_t* hdr);
node_t* make_list(int sz) {
	node_t* hdr = NULL;
	elem_t e;
	//printf("%d개의 숫자를 넣으세요..",sz);/
	for (int i = 0; i < sz; i++) {
		e = rand() % 100;
		hdr = insert_first(hdr, e);
	}
	return hdr;
}
node_t* hdr = NULL;
int run_menu() {
	int menu;
	int sz, index;
	elem_t val;
	node_t* prev;
	printf("\n(1) 새로 만들기, 개수  \t(2) 값 추가하기, 값  \n");
	printf("(3) 값 삭제하기, 값 \n");
	printf("(4) 값의 인덱스 찾기, 값\t(5) i번째 요소 찾기, i\n");
	printf("(6) i번째에 값 추가하기, i, 값\t(7) i번째 요소 삭제하기, i\n");
	printf("(8) 짝수 모두 1 증가\t(9) 리스트 뒤집기\t(0)종료 ... ");
	scanf("%d", &menu);
	switch (menu) {
	case 1:
		if (hdr != NULL) free_list(hdr);
		scanf("%d", &sz);
		hdr = make_list(sz);
		break;
	case 2:
		scanf("%d", &val);
		hdr = insert_first(hdr, val);
		break;
	case 3: // 값 삭제
		scanf("%d", &val);
		hdr = delete_val(hdr, val);
		break;
	case 4:  // 값으로 인덱스 찾기
		scanf("%d", &val);
		printf("%d 위치 = [%d]\n", val, index_of(hdr, val));
		break;
	case 5:  // i번째 요소 찾기기
		scanf("%d", &index);
		printf("[%d]번째 값 = %d\n", index, get(hdr, index));
		break;
	case 6:  // i번째에 값 추가하기
		scanf("%d %d", &index, &val);
		if (index == 0) {
			hdr = insert_first(hdr, val);
			break;
		}
		prev = get_node(hdr, index - 1);
		if (prev == NULL) break;
		insert_after(hdr, prev, val);
		break;
	case 7:  // index 번째 삭제
		scanf("%d", &index);
		if (index == 0) {
			hdr = delete_first(hdr);
			break;
		}
		prev = get_node(hdr, index - 1);
		if (prev == NULL) break;
		delete_after(hdr, prev);
		break;
	case 8:  // 짝수 모두 1 증가하기
		increase_all_even(hdr);
		break;
	case 9:  // 리스트 뒤집기
		hdr = reverse_list(hdr);
		break;
	default:
		menu = 0;
		break;
	}
	print_list(hdr);
	return menu != 0;
}

void main() {
	while (run_menu())
		;
	printf("\n안녕히 가세요\n");
}

node_t* reverse_list(node_t* hdr)
{
	node_t* prev, *p, *after;
	p = NULL;
	after = hdr;
	while (after != NULL)
	{
		prev = p;
		p = after;
		after = p->next;
		p->next = prev;
	}
	return p;
}

void increase_all_even(node_t* hdr)
{
	node_t* p = hdr;
	while (p != NULL)
	{
		if(p->data % 2 == 0)
			p->data++;
		p = p->next;
	}
}

node_t* get_node(node_t* hdr, int index) {
	node_t* p = hdr;
	int i = 0;
	while (p != NULL && i < index) {
		i++;
		p = p->next;
	}
	return p;
}
elem_t get(node_t* hdr, int index) {
	node_t* p = hdr;
	int i = 0;
	while (p != NULL && i < index) {
		i++;
		p = p->next;
	}
	if (p != NULL && i == index)
		return p->data;
	return err_elem;
}
int index_of(node_t* hdr, elem_t e) {
	node_t* p = hdr;
	int index = 0;
	while (p != NULL && p->data != e) {
		index++;
		p = p->next;
	}
	return index;
}
