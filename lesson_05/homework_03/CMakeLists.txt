cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(game)

add_executable(game 
  game.cpp
  utils.cpp)

message("!!! ${CMAKE_SOURCE_DIR}")

target_include_directories(game PRIVATE
  ${CMAKE_SOURCE_DIR}/iomodule/)

# target_compile_features(test PUBLIC cxx_std_17)


