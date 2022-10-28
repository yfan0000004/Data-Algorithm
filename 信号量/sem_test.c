/*
线程信号量的实践
gcc sem_test.c /home/yang/Data-Algorithm/dlist/dlist.a -I/home/yang/Data-Algorithm/dlist/inc -lpthread -o sem_test
*/
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#include"dlist.h"

pthread_mutex_t listlock;
pthread_cond_t cond;
sem_t sem;

void *ReadList(void *args)
{
    int j = 40;
    struct list* list = (struct list*)args;
    while(1){
        sem_wait(&sem);
        list_deleteAtTail(list);
        printf("删除元素后的链表：\n");
        printList(list);
        sleep(1);
    }
}

void *WriteList(void *args)
{
    //生成一个随机数
    srand(time(0)); 
    int j = 40;
    struct list* list = (struct list*)args;
    while(1){
        int a = 1 + (rand() % 1000);
        sem_post(&sem);
        list_addAtHead(list, a);
        printf("加入元素：%d 后的链表：\n", a);
        printList(list);
        sleep(1);
    }
}

int32_t main()
{
    pthread_mutex_init(&listlock, NULL); 
    pthread_cond_init(&cond, NULL);
    
    /*第二个参数pshared参数指定信号量的类型。
    如果其值为0，就表示这个信号量是当前进程的局部信号量，否则
    该信号量就可以在多个进程之间共享。
    value参数指定信号量的初始值
    */
    sem_init(&sem, 0, 0); 

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
    //初始化完毕链表后，可以将信号量+1
    sem_post(&sem);

    //打印最初的链表
    printf("最初的链表：\n");
    printList(list);

    pthread_create(&g_threadId1, NULL, WriteList, (void*)list);
    pthread_create(&g_threadId2, NULL, ReadList, (void*)list);

    sleep(1);
    
    //这是一种简单的线程同步的方式
    pthread_join(g_threadId2, NULL);//等待线程1结束
    pthread_join(g_threadId1, NULL);//等待线程2结束

    


    sleep(2);

    return 1;
}
