
include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  asiocmake
  GIT_REPOSITORY "https://github.com/OlivierLDff/asio.cmake"
  GIT_TAG        "main"
)

# Specify asio version
set(ASIO_TAG asio-1-21-0)
FetchContent_MakeAvailable(asiocmake)

add_executable(healthcheck_tests tests.cpp)
target_link_libraries(healthcheck_tests PRIVATE
    asio::asio
    gtest
    gmock
    gtest_main
)
