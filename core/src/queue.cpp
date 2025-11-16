#include "queue.h"

void init_link_q(LinkQueue& q){
    q.front = q.rear = nullptr;
}

bool link_queue_empty(LinkQueue& q){
    return q.front == nullptr;
}

void en_link_q(LinkQueue& q, struct Tree* elem){
    LinkNode* newNode = new LinkNode;
    newNode->data = elem;
    newNode->next = nullptr;
    
    if (link_queue_empty(q)) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

bool de_link_q(LinkQueue& q, struct Tree*& elem){
    if (link_queue_empty(q)) {
        return false;
    }
    
    LinkNode* temp = q.front;
    elem = temp->data;
    q.front = temp->next;
    
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    
    delete temp;
    return true;
}


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