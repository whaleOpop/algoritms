cmake_minimum_required(VERSION 3.5)

project(algoritms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(tests)
add_subdirectory(models)



add_executable(algoritms main.cpp)
target_link_libraries(algoritms BinaryInsertionSort ShakerSort Sort)

add_test(NAME run_bubble_sort_tests COMMAND SortingTests "[shaker_sort]")
add_test(NAME run_exchange_sort_tests COMMAND SortingTests "[binary_insertion_sort]")



enable_testing()