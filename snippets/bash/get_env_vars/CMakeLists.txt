cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER   /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(CMAKE_VAR "Text From CMakeLists.txt")

add_executable(executable main.cpp)
