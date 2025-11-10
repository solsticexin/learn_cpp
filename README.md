# Learn C++ Project

This is a standard C++ project using CMake 4.0 and C++20 standard.

## Project Structure

- `src/` - Source code files
- `include/` - Header files
- `CMakeLists.txt` - CMake configuration file
- `build/` - Build directory (not included in version control)

## Prerequisites

- CMake 4.0 or higher
- A C++20 compatible compiler (GCC 10+, Clang 10+, MSVC 2019+)

## Building the Project

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running the Project

After building, you can run the executable:

```bash
# On Linux/Mac
./bin/main

# On Windows
.\bin\main.exe
```

## Features

This project demonstrates several C++20 features:
- Range-based for loops
- Concepts (in Example.h)
- Standard ranges library (in Example.cpp)