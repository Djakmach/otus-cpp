cmake_minimum_required(VERSION 3.5)
# project(conteiners)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(tests 
    tests.cpp
    custom_containers/serial_container.h
    custom_containers/list_container.h)

target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/custom_containers/)

