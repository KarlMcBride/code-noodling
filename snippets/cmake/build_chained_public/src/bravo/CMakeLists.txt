project(bravo)

add_library(${PROJECT_NAME} bravo.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)

target_link_libraries(${PROJECT_NAME} PUBLIC charlie)
