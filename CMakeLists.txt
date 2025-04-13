cmake_minimum_required(VERSION 3.10)
project(Homeros)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(Lua REQUIRED)

if(NOT LUA_FOUND)
    message(FATAL_ERROR "Lua not found!")
endif()

include(sources.cmake)

add_executable(Homeros ${SOURCES})

target_include_directories(Homeros PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/scenes
    ${CMAKE_SOURCE_DIR}/src/ui
    ${CMAKE_SOURCE_DIR}/src/external/sol2/single
)

target_link_libraries(Homeros PRIVATE SDL2::SDL2 SDL2_image::SDL2_image SDL2_ttf::SDL2_ttf SDL2_mixer::SDL2_mixer ${LUA_LIBRARIES})
