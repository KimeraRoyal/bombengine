cmake_minimum_required(VERSION ${CMAKE_VERSION})
project(bombengine)

set(CMAKE_CXX_STANDARD 20)

include_directories(src)

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

#--------------------------------- STB -----------------------------------
set(STB_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/stb")

include_directories("${STB_DIR}")

#-------------------------------- ZLIB -----------------------------------
set(ZLIB_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/zlib")

if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(ZLIB_LIBRARIES_DIR "${ZLIB_DIR}/lib/x64")
    set(ZLIB_BINARIES_DIR "${ZLIB_DIR}/bin/x64")
else ()
    set(ZLIB_LIBRARIES_DIR "${ZLIB_DIR}/lib/x86")
    set(ZLIB_BINARIES_DIR "${ZLIB_DIR}/bin/x86")
endif()

set(ZLIB_LIBRARIES "${ZLIB_LIBRARIES_DIR}/zlib.lib")

string(STRIP "${ZLIB_LIBRARIES}" ZLIB_LIBRARIES)

include_directories("${ZLIB_DIR}/include")

#------------------------------- PUGIXML ---------------------------------
set(PUGIXML_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/pugixml")

if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(PUGIXML_LIBRARIES_DIR "${PUGIXML_DIR}/lib/x64")
    set(PUGIXML_BINARIES_DIR "${PUGIXML_DIR}/bin/x64")
else ()
    set(PUGIXML_LIBRARIES_DIR "${PUGIXML_DIR}/lib/x86")
    set(PUGIXML_BINARIES_DIR "${PUGIXML_DIR}/bin/x86")
endif()

set(PUGIXML_LIBRARIES "${PUGIXML_LIBRARIES_DIR}/pugixml.lib")

string(STRIP "${PUGIXML_LIBRARIES}" PUGIXML_LIBRARIES)

include_directories("${PUGIXML_DIR}/include")

#------------------------------- ASSIMP ----------------------------------
set(ASSIMP_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/assimp")

if(${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(ASSIMP_LIBRARIES_DIR "${ASSIMP_DIR}/lib/x64")
    set(ASSIMP_BINARIES_DIR "${ASSIMP_DIR}/bin/x64")
else ()
    set(ASSIMP_LIBRARIES_DIR "${ASSIMP_DIR}/lib/x86")
    set(ASSIMP_BINARIES_DIR "${ASSIMP_DIR}/bin/x86")
endif()

set(ASSIMP_LIBRARIES "${ASSIMP_LIBRARIES_DIR}/assimp-vc143-mt.lib")

string(STRIP "${ASSIMP_LIBRARIES}" ASSIMP_LIBRARIES)

include_directories("${ASSIMP_DIR}/include")

#------------------------------ RAPIDJSON --------------------------------
set(RAPIDJSON_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/rapidjson")

include_directories("${RAPIDJSON_DIR}/include")

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
        src/rendering/material/material.cpp
        src/rendering/camera/projection/orthographicprojection.cpp
        src/rendering/camera/projection/perspectiveprojection.cpp
        src/rendering/camera/camera.cpp
        src/rendering/shader/shadertype.h
)

target_link_libraries(rendering ${GLEW_LIBRARIES})
target_link_libraries(rendering opengl32)

#-------------------------------------------------------------------------
# Resource
#-------------------------------------------------------------------------

add_library(resources
        src/resources/resource.cpp
        src/resources/type/imagefile.cpp
        src/resources/type/modelfile.cpp
        src/resources/type/textfile.cpp
        src/resources/resources.cpp
        src/resources/type/materialfile.cpp
        src/resources/type/materialfile.h
)

target_link_libraries(resources ${SDL2_LIBRARIES})
target_link_libraries(resources ${ZLIB_LIBRARIES})
target_link_libraries(resources ${PUGIXML_LIBRARIES})
target_link_libraries(resources ${ASSIMP_LIBRARIES})

#-------------------------------------------------------------------------
# Core
#-------------------------------------------------------------------------

add_library(core
        src/core/core.cpp
        src/core/window/context.cpp
        src/core/window/window.cpp
        src/core/window/windows.cpp
        src/core/scene/scenes.cpp
        src/core/scene/scene.cpp
        src/core/input/mouse.cpp
        src/core/input/mouse.h
        src/core/input/keyboard.cpp
        src/core/input/keyboard.h
        src/core/utility/time.cpp
        src/core/utility/time.h
        src/core/utility/bitset.cpp
        src/core/utility/bitset.h
        src/core/input/input.cpp
        src/core/input/input.h
        src/core/scene/gameobject.cpp
        src/core/scene/gameobject.h
        src/core/scene/component.cpp
        src/core/scene/component.h
)

target_link_libraries(core rendering)
target_link_libraries(core resources)

add_custom_command(TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${GLEW_BINARIES_DIR}/glew32.dll"
        $<TARGET_FILE_DIR:core>)

add_custom_command(TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_LIBRARIES_DIR}/sdl2.dll"
        $<TARGET_FILE_DIR:core>)

add_custom_command(TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${ZLIB_BINARIES_DIR}/zlib1.dll"
        $<TARGET_FILE_DIR:core>)

add_custom_command(TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${PUGIXML_BINARIES_DIR}/pugixml.dll"
        $<TARGET_FILE_DIR:core>)

add_custom_command(TARGET core POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${ASSIMP_BINARIES_DIR}/assimp-vc143-mt.dll"
        $<TARGET_FILE_DIR:core>)

#-----------------------------------------------------------------------
# Demo
#-----------------------------------------------------------------------

add_executable(demo
        src/demo/main.cpp
        src/demo/demoscene.cpp
)

target_link_libraries(demo core)

add_custom_command(TARGET demo POST_BUILD
        COMMAND xcopy \"${CMAKE_CURRENT_LIST_DIR}/res\" \"$<TARGET_FILE_DIR:demo>/res\" /e /i /d /y)