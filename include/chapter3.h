#ifndef CHAPTER3_H
#define CHAPTER3_H

//第三题
bool Judge(char* A);
//question 4
namespace question4 {
typedef struct Node{
    char data;
    Node* next;
}LNode, *LinkList;
}
int dc(question4::LinkList L,int n);

namespace question5 {
    #ifndef MAXSIZE
    #define MAXSIZE

    #define maxsize 100
    #define elemtp int
    #endif

    typedef struct{
        elemtp stack[maxsize];
        int top[2];
    }stk;
    static stk s;
}
int push(int i, elemtp x );
#endif