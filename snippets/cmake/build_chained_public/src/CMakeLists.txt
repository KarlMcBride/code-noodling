# code-noodling/snippets/cmake/build_chained_public/src/CMakeLists.txt

project(build_chained_public)

add_subdirectory(alpha)
add_subdirectory(bravo)
add_subdirectory(charlie)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC alpha bravo charlie)
