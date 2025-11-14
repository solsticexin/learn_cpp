#ifndef STACK_H
#define STACK_H
#include <string>
#include <string_view>
#define MAX_SIZE 100
typedef struct{
int data[MAX_SIZE];
int top;
}Stack;
void init_stack(Stack& s); //初始化
bool stack_empty(Stack& s);
bool push(Stack& s ,int elem);
bool pop(Stack& s,int& pop_elem);
bool get_top(Stack& s,int& top_elem);

//链栈
typedef struct Node{ 
 int data[MAX_SIZE];
 Node* next;
}LinkStack;


//栈的应用
bool isValidParentheses(std::string_view sv);
std::string infixToPostfix(std::string_view infix);
std::string infixToPrefix(std::string_view infix);
#endif