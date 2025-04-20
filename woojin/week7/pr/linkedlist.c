#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
void print_list(node_t* hdr) {
    node_t* p = hdr;
    while (p != NULL) {
        printf("%3d ->", p->data);
        p = p->next;
    }
}
node_t* find_prev(node_t* hdr, elem_t e) {
    node_t* p = hdr;
    if (p == NULL) return p;
    while (p->next != NULL && p->next->data != e) {
        p = p->next;
    }
    if (p->next == NULL) return NULL;
    return p;
}
node_t* find(node_t* hdr, elem_t e) {
    node_t* p = hdr;
    while (p != NULL && p->data == e)
        p = p->next;
    return p;
}
node_t* new_node(elem_t e) {
    node_t* p = (node_t*)malloc(sizeof(node_t));
    p->data = e;
    p->next = NULL;
    return p;
}
node_t* insert_first(node_t* hdr, elem_t e) {
    node_t* p = new_node(e);
    p->next = hdr;
    return p;
}
void insert_after(node_t* hdr, node_t* prev, elem_t e) {
    node_t* p = new_node(e);
    p->next = prev->next;
    prev->next = p;
}
node_t* delete_first(node_t* hdr) {
    node_t* p;
    p = hdr->next;
    free(hdr);
    return p;  // p가 새로운 헤더임
}
node_t* delete_val(node_t* hdr, elem_t e) {
    node_t* p;
    if (hdr == NULL) return hdr;
    if (hdr->data == e) { // 헤더면… 헤더를 삭제
        return delete_first(hdr);
    }
    p = find_prev(hdr, e);  // 직전 노드를 찾음
    if (p == NULL) {
        return hdr;   // 없으면 그냥 리턴
    }
    delete_after(hdr, p);  // hdr와 p는 NULL이 아님
    return hdr;
}
void delete_after(node_t* hdr, node_t* prev) {
    node_t* p = prev->next;  // 순서 중요
    prev->next = p->next;
    free(p);
}
void free_list(node_t* hdr) {
    node_t* ptr = hdr, *p;
    while (ptr != NULL) {
        p = ptr->next;
        free(ptr);
        ptr = p;
    }
}