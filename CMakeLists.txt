cmake_minimum_required(VERSION 3.5)

project(algoritms)
add_subdirectory(models)

add_executable(algoritms main.cpp)
target_link_libraries(algoritms Sort BubbleSort ImprovedBubbleSort InsertionSort SelectionSort)