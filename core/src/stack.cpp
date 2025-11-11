#include "stack.h"

void init_stack(Stack& s){s.top=-1;}
bool stack_empty(Stack& s){return s.top == -1;}
bool push(Stack& s, int elem){
    if(s.top == MAX_SIZE-1) return false;
    s.data[++s.top]=elem;
    return true;
}
bool pop(Stack& s, int& pop_elem){
    if(stack_empty(s)) return true;
    pop_elem=s.data[s.top--];
    return true;
}
bool get_top(Stack &s, int &top_elem){
    if(stack_empty(s)) return true;
    top_elem=s.data[s.top];
    return true;
}