cmake_minimum_required(VERSION 3.10)

project(main)

add_library(man_lib
src/persistence.cpp
src/manager.cpp
)

target_include_directories(man_lib PUBLIC ${CMAKE_SOURCE_DIR}/src/include)

add_executable(main src/main.cpp)

target_link_libraries(main
    PRIVATE 
        man_lib
)


enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

# Prevent overriding parent project settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# ---- Tests ----
add_executable(my_tests
    tests/test_example.cpp
)

target_link_libraries(my_tests
    PRIVATE
        man_lib
        GTest::gtest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(my_tests)