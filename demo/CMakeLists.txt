cmake_minimum_required(VERSION 3.10)           # 指定CMake的最低版本
project(demo)                                  # 项目名称

set(CMAKE_CXX_STANDARD 11)                     # 使用C++11标准

include_directories(include)                   # 包含头文件目录

add_executable(demo
    src/main.cpp
    src/matrix.cpp                             # 如果有matrix.cpp实现文件
)