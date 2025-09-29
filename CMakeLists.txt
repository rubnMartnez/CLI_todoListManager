cmake_minimum_required(VERSION 3.10)

project(main)

set(SOURCES src/main.cpp
    src/persistence.cpp
    src/manager.cpp
)

add_executable(main ${SOURCES})

target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/src/include)