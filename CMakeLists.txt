cmake_minimum_required(VERSION 3.26)
project(bombengine)

set(CMAKE_CXX_STANDARD 20)

#-------------------------------------------------------------------------
# Libraries
#-------------------------------------------------------------------------

find_package(OpenGL REQUIRED)

#--------------------------------- GLEW ----------------------------------
set(GLEW_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/glew")

if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(GLEW_LIBRARIES_DIR "${GLEW_DIR}/lib/Release/x64")
    set(GLEW_BINARIES_DIR "${GLEW_DIR}/bin/Release/x64")
else ()
    set(GLEW_LIBRARIES_DIR "${GLEW_DIR}/lib/Release/Win32")
    set(GLEW_BINARIES_DIR "${GLEW_DIR}/bin/Release/Win32")
endif()

set(GLEW_LIBRARIES "${GLEW_LIBRARIES_DIR}/glew32.lib")

string(STRIP "${GLEW_LIBRARIES}" GLEW_LIBRARIES)

include_directories("${GLEW_DIR}/include")

#--------------------------------- SDL2 ----------------------------------
set(SDL2_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/SDL2")

if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_LIBRARIES_DIR "${SDL2_DIR}/lib/x64")
else ()
    set(SDL2_LIBRARIES_DIR "${SDL2_DIR}/lib/x86")
endif()

set(SDL2_LIBRARIES "${SDL2_LIBRARIES_DIR}/SDL2.lib;${SDL2_LIBRARIES_DIR}/SDL2main.lib")

string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)

include_directories("${SDL2_DIR}/include")

#--------------------------------- GLM -----------------------------------
set(GLM_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/glm")

include_directories("${GLM_DIR}")

include_directories(src)

#-------------------------------------------------------------------------
# Rendering
#-------------------------------------------------------------------------

add_library(rendering
        src/rendering/texture/texture.cpp
        src/rendering/texture/renderbuffer.cpp
        src/rendering/texture/colorbuffer.cpp
        src/rendering/texture/framebuffer.cpp
        src/rendering/model/buffer.cpp
        src/rendering/model/vertexarray.cpp
        src/rendering/shader/shader.cpp
        src/rendering/shader/shaderprogram.cpp
        src/rendering/model/mesh.cpp
        src/rendering/model/model.cpp
)

target_link_libraries(rendering ${GLEW_LIBRARIES})
target_link_libraries(rendering opengl32)

add_custom_command(TARGET rendering POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLEW_BINARIES_DIR}/glew32.dll"
        $<TARGET_FILE_DIR:core>)

#-------------------------------------------------------------------------
# Core
#-------------------------------------------------------------------------

add_library(core
        src/core/core.cpp
        src/core/window/window.cpp
        src/core/window/context.cpp
)

target_link_libraries(core rendering)
target_link_libraries(core ${SDL2_LIBRARIES})

add_custom_command(TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_LIBRARIES_DIR}/sdl2.dll"
        $<TARGET_FILE_DIR:core>)

#-------------------------------------------------------------------------
# Demo
#-------------------------------------------------------------------------

add_executable(demo src/main.cpp)

target_link_libraries(demo core)