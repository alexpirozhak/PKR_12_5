cmake_minimum_required(VERSION 3.27)
project(PKR_12_5)

set(CMAKE_CXX_STANDARD 17)

add_executable(PKR_12_5 main.cpp
        Stack.cpp)
add_subdirectory(Google_tests)
