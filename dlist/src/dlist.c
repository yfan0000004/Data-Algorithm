#include "dlist.h"

struct list* list_creat(){
    struct list* node = (struct list*)malloc(sizeof(struct list));
    node->val = 0;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

struct list* list_creat(int val){
    struct list* node = (struct list*)malloc(sizeof(struct list));
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void list_creat(struct list *list){
    return;
}

void list_add(struct list *list, struct list *new_item)