cmake_minimum_required(VERSION 3.8)
project(GoogleCodeJam)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Practice.cpp)
add_executable(Practice ${SOURCE_FILES})
add_executable(A A.cpp)
add_executable(B B.cpp)