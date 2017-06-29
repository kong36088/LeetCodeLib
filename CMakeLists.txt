cmake_minimum_required(VERSION 3.7)
project(C__Code)

set(CMAKE_CXX_STANDARD 11)

INCLUDE_DIRECTORIES(
        /lib
)
set(SOURCE_FILES main.cpp StringUtils.h BinaryTree.h VectorHelper.h)

add_executable(C__Code ${SOURCE_FILES})