cmake_minimum_required(VERSION 3.10)

project(SortingTests)

include(FetchContent)
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0  
)
FetchContent_MakeAvailable(gtest)

add_executable(SortingTests
    BubbleSortTest.cpp
    ExchangeSortTest.cpp
    ImprovedBubbleSortTest.cpp
    InsertionSortTest.cpp
    SelectionSortTest.cpp
  
)

target_link_libraries(SortingTests gtest gtest_main)
