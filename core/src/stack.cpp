#include "stack.h"
// #include <print>
#include <stack>
#include <string>
#include <string_view>
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
bool isValidParentheses(std::string_view sv){
    std::stack<char> st{};
    std::string_view temp{};
    for(auto c=sv.begin();c!=sv.end();++c){
        if (*c=='(' || *c=='[' || *c=='{') {
            st.push(*c);
        }else if (*c==')') {
            if(st.empty() || st.top()!='('){return false;}
            st.pop();
        }else if(*c==']'){
            if(st.empty() || st.top()!='['){return false;}
            st.pop();
        }else if(*c=='}'){
            if(st.empty() || st.top()!='{'){return false;}
            st.pop();
        }
    }
    return st.empty();
}

std::string infixToPostfix(std::string_view infix){
    std::stack<char> stack{};
    std::string postfix{};
    auto precedence=[](char op){
        if(op=='+' ||op=='-')return 1;
        if(op=='*' || op=='/') return 2;
        return 0;
    };
    auto isDigit=[](char c){
        if(c>=48 && c<=57) return true;
        return false;
    };
    auto isOperator=[](char c){
        if(c=='+'||c=='-'||c=='*'||c=='/')return true;
        return false;
    };
    auto isOperand=[](char c){
        return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
    };
    // auto transfer=[&postfix](char c){
    //     postfix +=c;
    //     postfix +=' ';
    // };
    for(auto c:infix){
        if (isDigit(c)||isOperand(c)) {
            postfix+=c;
            postfix+=' ';
        }else if (isOperator(c)) {
            while(!stack.empty() &&stack.top()!='('
                 && precedence(stack.top())>=precedence(c)
                 ){
                    postfix+=stack.top();
                    postfix+=' ';
                    stack.pop();
                 }
            stack.push(c);
        }else if (c=='(') {
            stack.push(c);
        }else if (c==')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix+=stack.top();
                postfix+=' ';
                stack.pop();
            }
            if(!stack.empty()&&stack.top()=='(') stack.pop();
        }
        // else {
        //     if(isOperand(c)){
        //         postfix+=c;
        //         postfix+=' ';
        //     }
        // }
    }
    while(!stack.empty()){
        postfix+=stack.top();
        postfix+=' ';
        stack.pop();
    }
    //移除最后一个空格
    if(!postfix.empty()&&postfix.back()==' ')
        postfix.pop_back();
    return postfix;
}