cmake_minimum_required(VERSION 3.10)

project(algoritms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(tests)
add_subdirectory(models)



add_executable(algoritms main.cpp)
target_link_libraries(algoritms QuickSort ShellSort Sort)

add_test(NAME run_shell_sort_tests COMMAND SortingTests "[shell_sort]")
add_test(NAME run_quick_sort_tests COMMAND SortingTests "[quick_sort]")



enable_testing()