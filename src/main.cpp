#include <iostream>
#include <string>
#include <vector>

// 如果有自定义头文件，可以这样包含
// #include "MyClass.h"

int main() {
    std::cout << "Hello, C++20 with CMake 4.0!" << std::endl;
    
    // 使用C++20的新特性示例
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    // C++20范围for循环的新特性
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::string s{"你好，世界！"};
    std::cout << s <<std::endl;
    return 0;
}