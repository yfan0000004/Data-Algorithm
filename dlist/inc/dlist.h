#include <stdio.h>
#include <stdlib.h>

struct list{
    int val;
    struct list *prev;
    struct list *next;
}

struct list* list_creat();
struct list* list_creat(int val);
void list_creat(struct list *list);
void list_add(struct list *list, struct list *new_item);
void list_delete(struct list *item);
int list_is_empty(struct list *list);
void list_splice(struct list *dst, struct list *src);