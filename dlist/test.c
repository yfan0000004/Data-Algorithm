#include <time.h>
#include"dlist.h"

int main(){
    
    //创建链表
    struct list* list = list_creat();
    
    //初始化链表，先插入10个随机数
    srand(time(0)); 
    for(int i = 0; i < 10; i++){
        int a = 1 + (rand() % 100);
        list_addAtHead(list, a);
    }
    printList(list);

    list_deleteAtTail(list);
    printList(list);
    
    list_deleteAtTail(list);
    printList(list);  
    return 1;
}
