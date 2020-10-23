cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(executable main.cpp reader.cpp writer.cpp)
