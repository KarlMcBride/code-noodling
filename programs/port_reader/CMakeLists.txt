cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)

project(port_reader)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC pthread)
