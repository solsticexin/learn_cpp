cmake_minimum_required(VERSION 4.0)

project(LearnCppProject VERSION 1.0.0 LANGUAGES CXX)

if(MSVC)
    add_compile_options("/utf-8")
endif()


# 设置C++标准为C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 包含头文件目录
include_directories(include)
include_directories(core/include)

# 添加所有源文件
file(GLOB SOURCES "src/*.cpp" "core/src/*.cpp")

# 添加可执行文件
add_executable(main ${SOURCES})