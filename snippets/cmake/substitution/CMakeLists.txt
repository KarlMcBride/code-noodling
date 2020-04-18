cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_COMPILER   /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

set(VAR_TO_BE_SUBSTITUTED "Text From CMakeLists.txt")

configure_file( main.in.cpp main.cpp )

add_executable(executable main.cpp)
