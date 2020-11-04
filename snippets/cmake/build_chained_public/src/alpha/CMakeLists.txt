project(alpha)

add_library(${PROJECT_NAME} alpha.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} PUBLIC bravo)
