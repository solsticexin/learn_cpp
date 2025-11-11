#include "queue.h"

void init_queue(Queue& q){
    q.front=q.rear=0;
}
bool queue_empty(Queue &q){
    if(q.front==q.rear) return true;
    else return false;
}
bool en_queue(Queue &q,int elem){
    if((q.rear+1) % QUEUE_MAX_EIZE ==q.front) return false;
    q.data[q.rear]=elem;
    q.rear=(q.rear+1)%QUEUE_MAX_EIZE;
    return true;
}
bool de_queue(Queue &q, int &elem){
    if(queue_empty(q)) return false;
    elem =q.data[q.front];
    q.front=(q.front+1)%QUEUE_MAX_EIZE;
    return true;
}