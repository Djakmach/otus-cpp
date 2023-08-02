cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

project(game)

add_executable(game game.cpp)
target_compile_features(test PUBLIC cxx_std_17)


