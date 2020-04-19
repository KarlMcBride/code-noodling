cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 14)

project(main)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC calculator)