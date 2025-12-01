export module queue;
import tree;
#define QUEUE_MAX_EIZE 100

export typedef struct node {
    struct Tree* data;
    struct node* next;
}LinkNode;

export typedef struct {
    LinkNode* front;
    LinkNode* rear;
}LinkQueue;

export inline void init_link_q (LinkQueue& q) { q.front = q.rear = nullptr; }
export void en_link_q (LinkQueue& q, struct Tree* elem);
export bool de_link_q (LinkQueue& q, struct Tree*& elem);
export inline bool link_queue_empty (LinkQueue& q) { return q.front == nullptr; }


//循环队列
export typedef struct {
    int data[QUEUE_MAX_EIZE];
    int front;
    int rear;
}Queue;

export inline void init_queue (Queue& q){ q.front = q.rear = 0; }

/*
循环队列判断对满还是队空有三种处理方式
1.牺牲一个存储单元来作判断,这样入队时会少用到那个空间
对满:(rear+1)%max_size==front
对空:rear==front
队列中的元素:(rear-front+max_size)%max_size

2.添加成员变量记录队列实际存储元素大小

3.添加tag标签 这样入队时只可能时对满,出队时只可能时队空 即修改tag标签

*/

//采用方法1.
export inline bool queue_empty (Queue& q) {
    if (q.front == q.rear) return true;
    else return false;
} 
export bool en_queue (Queue& q, int elem) {
    if ((q.rear + 1) % QUEUE_MAX_EIZE == q.front) return false;
    q.data[q.rear] = elem;
    q.rear = (q.rear + 1) % QUEUE_MAX_EIZE;
    return true;
}
export bool de_queue (Queue& q, int& elem) {
    if (queue_empty (q)) return false;
    elem = q.data[q.front];
    q.front = (q.front + 1) % QUEUE_MAX_EIZE;
    return true;
}