cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 11)

#set(ENV{PATH} $PATH:/usr/bin/make)
set(CMAKE_C_COMPILER   /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

project(Template_Class)

include_directories(.)

add_library(TestTemp TestTemp.cpp)

add_executable(template_class.ex main.cpp)

target_link_libraries(template_class.ex TestTemp)