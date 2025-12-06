export module stack;

import <string>;
import <string_view>;
#define MAX_SIZE 100
export typedef struct {
	int data[MAX_SIZE];
	int top;
}Stack;
export inline void init_stack (Stack& s) { s.top = -1; }//初始化
export inline bool stack_empty (Stack& s) { return s.top == -1; }
export bool push (Stack& s, int elem) {
	if (s.top == MAX_SIZE - 1) return false;
	s.data[++s.top] = elem;
	return true;
}
export bool pop (Stack& s, int& pop_elem) {
	if (stack_empty (s)) return true;
	pop_elem = s.data[s.top--];
	return true;
}
export bool get_top (Stack& s, int& top_elem) {
	if (stack_empty (s)) return true;
	top_elem = s.data[s.top];
	return true;
}

//链栈
export typedef struct LinkNode {
	int data[MAX_SIZE];
	LinkNode* next;
}LinkStack;


//栈的应用
export bool is_valid_parentheses (std::string_view sv);
export std::string infix_to_postfix (std::string_view infix);
export std::string infix_to_prefix (std::string_view infix);