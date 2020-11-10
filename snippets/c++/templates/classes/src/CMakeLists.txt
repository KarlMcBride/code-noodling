cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 11)

project(template_classes)

add_executable(${PROJECT_NAME} main.cpp boat.cpp tank.cpp vehicle_handler.cpp)
