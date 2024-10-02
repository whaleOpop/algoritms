cmake_minimum_required(VERSION 3.5)

project(algoritms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(tests)
add_subdirectory(models)



add_executable(algoritms main.cpp)
target_link_libraries(algoritms BubbleSort ExchangeSort ImprovedBubbleSort InsertionSort SelectionSort Sort)


