cmake_minimum_required(VERSION 3.1)
project(StudentCard VERSION 0.1.0 LANGUAGES CXX)
add_executable(main main.cpp EulerSolver.cpp Function.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17  -O0")