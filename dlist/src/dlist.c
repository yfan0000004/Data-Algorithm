#include "dlist.h"

//创建链表
struct list* list_creat(){
    struct list* node = (struct list*)malloc(sizeof(struct list));
    node->val = -1;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

//头插法插入元素
void list_addAtHead(struct list* list, int val){
    struct list* cur = (struct list*)malloc(sizeof(struct list));
    struct list* head = list;
    cur->val = val;
    cur->next = head->next;
    cur->prev = head;
    head->next = cur;
    if(cur->next != NULL) cur->next->prev = cur;
    return;
}

//尾插法插入元素
void list_addAtTail(struct list* list, int val){
    struct list* node = (struct list*)malloc(sizeof(struct list));
    struct list* cur = list;
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = node;
    node->prev = cur;
    node->next = NULL;
    return;
}

//删除链表尾部元素
void list_deleteAtTail(struct list *list){
    struct list* cur = list;
    while(cur->next != NULL)
        cur = cur->next;
    struct list* deleteNode = cur;
    cur->prev->next = NULL;
    cur->prev = NULL;
    free(deleteNode);
}

/*/连接两个链表
struct list* list_splice(struct list *dst, struct list *src){
    struct list* head = dst;
    while(head->next != NULL){
        head = head->next;
    }
    printf("当前节点的值：%d\n", head->val);
    head->next = src;
    src->prev = head;
    return dst;
}*/

void printList(struct list *list){
    if(list->next != NULL){
        while(list->next != NULL){
            list = list->next;
            printf(" %d -> ",list->val);
         }
         printf(" NULL\n");
    } 
    else{
        printf("empty\n");
    }
}