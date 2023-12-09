cmake_minimum_required(VERSION 3.26)
project(rewrite_singly_linked_list_cpp)
################################
# GTest
################################
enable_testing()
find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES main.cpp
        SinglyLinkedList.h
        SinglyLinkedList.cpp
        Util.hpp
        LinkedListTest.cpp)
add_executable(rewrite_singly_linked_list_cpp ${SOURCE_FILES} )
################################
# Unit Tests
################################
# Add test cpp file

# Link test executable against gtest & gtest_main
target_link_libraries(rewrite_singly_linked_list_cpp GTest::GTest GTest::Main)
add_test(test-1 rewrite_singly_linked_list_cpp)