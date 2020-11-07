cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 11)

project(Threads)

add_executable(threads.ex main.cpp)

target_link_libraries(threads.ex PUBLIC pthread)