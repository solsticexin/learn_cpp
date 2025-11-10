#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <string>
#include <vector>

class Example {
public:
    Example();
    ~Example();
    
    void printMessage(const std::string& message);
    
    // C++20特性示例：概念（Concepts）
    template<typename T>
    void printVector(const std::vector<T>& vec);
    
private:
    std::string prefix;
};

#endif // EXAMPLE_H