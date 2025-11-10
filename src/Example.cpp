#include "Example.h"
#include <iostream>
#include <ranges>

Example::Example() : prefix("[INFO] ") {
}

Example::~Example() {
}

void Example::printMessage(const std::string& message) {
    std::cout << prefix << message << std::endl;
}

// C++20特性示例：概念（Concepts）和范围库
template<typename T>
void Example::printVector(const std::vector<T>& vec) {
    std::cout << prefix << "Vector contents: ";
    // 使用C++20范围库的新特性
    for (const auto& item : vec | std::views::take(5)) {  // 只取前5个元素
        std::cout << item << " ";
    }
    std::cout << std::endl;
}