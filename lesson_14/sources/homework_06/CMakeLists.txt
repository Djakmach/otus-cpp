cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(game)

add_executable(game 
  main.cpp)

message("!!! ${CMAKE_SOURCE_DIR}")

