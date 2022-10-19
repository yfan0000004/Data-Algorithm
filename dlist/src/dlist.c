#include "dlist.h"

//创建链表
struct list* list_creat(){
    struct list* node = (struct list*)malloc(sizeof(struct list));
    node->prev = NULL;
    node->next = NULL;
    return node;
}

/*
struct list* list_creat(int val){
    struct list* node = (struct list*)malloc(sizeof(struct list));
    node->val = val;
    node->prev = NULL;
    node->next = NULL;
    return node;
}*/

void list_creat(struct list *list){
    return;
}

//头插法插入元素
void list_add(struct list* list, struct list* new_item){
    struct list* head = list;
    //struct list* cur = (struct list*)malloc(sizeof(struct list));
    new_item->next = head->next;
    new_item->prev = head;
    head->next = new_item;
    if(new_item->next != NULL) new_item->next->cur = new_item;
    return;
}

//删除整个链表
void list_delete(struct list *item){
    while(item->next != NULL){
        struct list* head = item;
        item = item->next;
        free(head);
    }
    free(item);
}

//判断链表是否为空 1为空 0不为空
int list_is_empty(struct list *list){
    if(list == NULL) return 1;
    return 0; 
}

//连接两个链表
struct list* list_splice(struct list *dst, struct list *src){
    struct list* head = dst;
    while(dst->next != NULL){
        dst = dst->next;
    }
    dst-next = src;
    src-prev = dst;
    return head;
}