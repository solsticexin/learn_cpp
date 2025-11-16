#ifndef QUEUE_H
#define QUEUE_H
#include "tree.h"
#define QUEUE_MAX_EIZE 100

typedef struct node{
    struct Tree* data;
    struct node* next;
}LinkNode;

typedef struct{
    LinkNode* front;
    LinkNode* rear;
}LinkQueue;

void init_link_q(LinkQueue& q);
void en_link_q(LinkQueue& q, struct Tree* elem);
bool de_link_q(LinkQueue& q, struct Tree*& elem);
bool link_queue_empty(LinkQueue& q);


//循环队列
typedef struct{
    int data[QUEUE_MAX_EIZE];
    int front;
    int rear;
}Queue;

void init_queue(Queue& q);

/*
循环队列判断对满还是队空有三种处理方式
1.牺牲一个存储单元来作判断,这样入队时会少用到那个空间
对满:(rear+1)%max_size==front
对空:rear==front
队列中的元素:(rear-front+max_size)%max_size

2.添加成员变量记录队列实际存储元素大小

3.添加tag标签 这样入队时只可能时对满,出队时只可能时队空 即修改tag标签

*/
bool queue_empty(Queue& q); //采用方法1.
bool en_queue(Queue& q,int elem);
bool de_queue(Queue& q,int& elem);
#endif