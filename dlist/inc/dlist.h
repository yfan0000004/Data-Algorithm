#include <stdio.h>
#include <stdlib.h>

struct list{
    int val;
    struct list *prev;
    struct list *next;
};

//struct list* list_creat();
struct list* list_creat();
void list_addAtTail(struct list *list, int val);
void list_addAtHead(struct list *list, int val);
void list_addAtIndex(struct list *list, int val, int index);
void list_deleteAtTail(struct list *list);
void printList(struct list *list);