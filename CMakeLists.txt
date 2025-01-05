cmake_minimum_required(VERSION 3.10)

project(algoritms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(tests)
add_subdirectory(models)



add_executable(algoritms main.cpp)
target_link_libraries(algoritms NaturalMergeSort SinglePhaseMergeSort TwoPhaseMergeSort Sort)

add_test(NAME run_natural_merge_sort_tests COMMAND SortingTests "[natural_merge_sort]")
add_test(NAME run_single_phase_merge_sort_tests COMMAND SortingTests "[single_phase_merge_sort]")
add_test(NAME run_two_phase_merge_sort_tests COMMAND SortingTests "[two_phase_merge_sort]")



enable_testing()