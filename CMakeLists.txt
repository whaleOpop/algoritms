cmake_minimum_required(VERSION 3.5)

project(algoritms)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(tests)
add_subdirectory(models)



add_executable(algoritms main.cpp)
target_link_libraries(algoritms BubbleSort ExchangeSort ImprovedBubbleSort InsertionSort SelectionSort Sort)

add_test(NAME run_bubble_sort_tests COMMAND SortingTests "[bubble_sort]")
add_test(NAME run_exchange_sort_tests COMMAND SortingTests "[exchange_sort]")
add_test(NAME run_improved_bubble_sort_tests COMMAND SortingTests "[improved_bubble_sort]")
add_test(NAME run_insertion_sort_tests COMMAND SortingTests "[insertion_sort]")
add_test(NAME run_selection_sort_tests COMMAND SortingTests "[selection_sort]")


enable_testing()