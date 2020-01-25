cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 11)

#set(ENV{PATH} $PATH:/usr/bin/make)
set(CMAKE_C_COMPILER   /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(ColumnedFiling)

include_directories(.)

add_executable(columned_filing.ex main.cpp)