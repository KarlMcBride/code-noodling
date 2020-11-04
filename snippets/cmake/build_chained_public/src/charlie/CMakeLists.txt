project(charlie)

add_library(${PROJECT_NAME} charlie.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)
