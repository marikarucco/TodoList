cmake_minimum_required(VERSION 3.26)
project(TodoList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

set(SOURCE_FILES Activity.h ActivityList.cpp ActivityList.h)
add_executable(todolist main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(todolist core)