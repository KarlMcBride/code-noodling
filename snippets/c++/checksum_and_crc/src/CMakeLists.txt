cmake_minimum_required(VERSION 3.7.2)
set(CMAKE_CXX_STANDARD 11)

project(checksum_and_crc)

add_executable(${PROJECT_NAME} main.cpp checksum.cpp crc.cpp)
