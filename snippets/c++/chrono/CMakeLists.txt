cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)

add_executable(executable main.cpp)

target_link_libraries(executable PUBLIC pthread)
