#include <unistd.h>
#include <pthread.h>
#include <time.h>

#include"dlist.h"

pthread_mutex_t listlock;

void *ReadList(void *args)
{
    struct list* list = (struct list*)args;
    while(1){
        pthread_mutex_lock(&listlock);
        list_deleteAtTail(list);
        printf("删除元素后的链表：\n");
        printList(list);
        pthread_mutex_unlock(&listlock);
        sleep(2);
    }
    
}

void *WriteList(void *args)
{
    //生成一个随机数
    srand(time(0)); 
    struct list* list = (struct list*)args;
    while(1){
        int a = 1 + (rand() % 1000);
        pthread_mutex_lock(&listlock);
        list_addAtHead(list, a);
        printf("加入元素：%d 后的链表：\n", a);
        printList(list);
        pthread_mutex_unlock(&listlock);
        sleep(2);
    }
}

int32_t main()
{
    pthread_mutex_init(&listlock, NULL);
    pthread_t g_threadId1;
    pthread_t g_threadId2;

    //创建链表
    struct list* list = list_creat();
    
    //初始化链表，先插入10个随机数
    srand(time(0)); 
    for(int i = 0; i < 10; i++){
        int a = 1 + (rand() % 1000);
        list_addAtHead(list, a);
    }

    //打印最初的链表
    printf("最初的链表：\n");
    printList(list);

    pthread_create(&g_threadId1, NULL, WriteList, (void*)list);
    pthread_create(&g_threadId2, NULL, ReadList, (void*)list);

    sleep(20);

    return 1;
}
