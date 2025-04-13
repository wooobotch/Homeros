cmake_minimum_required(VERSION 3.10)
project(Homeros)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} src src/scenes)

include(sources.cmake)

#set(SOURCES
#    src/main.cpp
#    src/game.cpp
#    src/window.cpp

#    src/renderer.cpp
#    src/input_handler.cpp
#    src/audio_manager.cpp
#    src/scene_manager.cpp
#    src/scenes/game_scene.cpp
#    src/scenes/menu_scene.cpp
#    src/scenes/options_scene.cpp
#    src/scenes/splash_screen_scene.cpp
#)

add_executable(Homeros ${SOURCES})

target_link_libraries(Homeros PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf SDL2_mixer::SDL2_mixer)
