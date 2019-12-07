cmake_minimum_required(VERSION 3.10)
project(task2)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_subdirectory(src)


find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIR})

add_executable(main main.cpp)
target_link_libraries (main TFactory TFunction)


add_executable(test_main test.cpp)
target_link_libraries(test_main TFactory TFunction  gtest gtest_main)











