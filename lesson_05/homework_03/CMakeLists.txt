cmake_minimum_required(VERSION 3.26)

project(game)

add_executable(game game.cpp)

add_executable(test test.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)