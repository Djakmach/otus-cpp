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


add_executable(containers_test 
  list_container_test.cpp 
  serial_container_test.cpp
)

target_include_directories(
  containers_test PUBLIC ${CMAKE_SOURCE_DIR}/../../lesson_14_containers/homework_06/custom_containers
)

target_link_libraries(containers_test PUBLIC gtest_main)