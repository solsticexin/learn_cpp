export module chapter3;

//µÚÈýÌâ
export bool judge (char* A);
//question 4
export namespace question4 {
    export typedef struct Node {
        char data;
        Node* next;
    }LNode, * LinkList;
}
export int dc (question4::LinkList L, int n);

export namespace question5 {
//#ifndef MAXSIZE
    #define MAXSIZE
    #define maxsize 100
    #define elemtp int
//#endif

    export typedef struct {
        elemtp stack[maxsize];
        int top[2];
    }stk;
    export inline stk s {};
}
export int push (int i, elemtp x);