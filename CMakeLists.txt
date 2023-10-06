cmake_minimum_required(VERSION 3.26)
project(bombengine)

set(CMAKE_CXX_STANDARD 20)

# SDL2
set(SDL2_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/SDL2")

if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES_DIR "${SDL2_DIR}/lib/x64")
else ()
    set(SDL2_LIBRARIES_DIR "${SDL2_DIR}/lib/x86")
endif()

set(SDL2_LIBRARIES "${SDL2_LIBRARIES_DIR}/SDL2.lib;${SDL2_LIBRARIES_DIR}/SDL2main.lib")

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

include_directories("${SDL2_DIR}/include")

include_directories(src)

add_executable(demo src/main.cpp)

add_library(core
        src/core/core.cpp
        src/core/window/window.cpp
)

target_link_libraries(core ${SDL2_LIBRARIES})

target_link_libraries(demo core)

add_custom_command(TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_LIBRARIES_DIR}/sdl2.dll"
        $<TARGET_FILE_DIR:core>)