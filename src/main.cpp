#include <print>
#include <string>
#include "../core/include/stack.h"
int main() {
    std::println("Learn data structure");
    std::string s{"{([])}"};
    if(isValidParentheses(s)){
        std::println("Success");
    }else std::println("Failure");
    std::println("你好世界");   
    return 0;
}