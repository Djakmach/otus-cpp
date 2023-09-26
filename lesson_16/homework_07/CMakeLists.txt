cmake_minimum_required(VERSION 3.5)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_executable(containers_tests 
  list_container_tests.cpp 
  serial_container_tests.cpp
)

target_include_directories(
  containers_tests PUBLIC ${CMAKE_SOURCE_DIR}/../../lesson_14/homework_06/custom_containers
)

target_link_libraries(containers_tests PUBLIC gtest_main)