cmake_minimum_required(VERSION 3.10)
project(Homeros)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

set(SOURCES
    src/main.cpp
    src/game.cpp
    src/scene_manager.cpp
    src/audio_manager.cpp
    src/renderer.cpp
    src/input_handler.cpp
)

include_directories(${SDL2_INCLUDE_DIRS} src)
include(sources.cmake)

add_executable(Homeros ${SOURCES})

target_link_libraries(Homeros ${SDL2_LIBRARIES})
