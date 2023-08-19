cmake_minimum_required(VERSION 3.7.2)
project(polymorphism)

set(CMAKE_CXX_STANDARD 17 REQUIRED)

add_executable(inheritance.square-rect 1.inheritance.square-rect.cpp)
add_executable(inheritance.try-poly 2.inheritance.try-poly.cpp)
add_executable(virtual 3.virtual.cpp)

file(GLOB SHAPES_SOURCES 4.shapes/*.cpp)
add_executable(shapes ${SHAPES_SOURCES})

add_executable(accessibility_of_inherited_members accessibility_of_inherited_members.cpp)