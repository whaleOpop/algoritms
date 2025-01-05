cmake_minimum_required(VERSION 3.10)

project(SortingTests)

include(FetchContent)
FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.7.1
)
FetchContent_MakeAvailable(catch2)


enable_testing()

add_executable(SortingTests
    QuickSortTest.cpp
    ShellSortTest.cpp
)

target_link_libraries(SortingTests
    PRIVATE
    ShellSort
    QuickSort
    Sort
)


target_link_libraries(SortingTests PRIVATE Catch2::Catch2WithMain)

