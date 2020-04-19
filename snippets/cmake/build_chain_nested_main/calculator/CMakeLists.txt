cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 14)

project(calculator)

add_library(${PROJECT_NAME} calculator.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)