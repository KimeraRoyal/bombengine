cmake_minimum_required(VERSION 3.26)
project(bombengine)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

add_executable(demo src/main.cpp)

add_library(core src/core/core.cpp)

target_link_libraries(demo core)