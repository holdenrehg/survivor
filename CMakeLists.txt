cmake_minimum_required(VERSION 3.11)

project(Survivor VERSION 0.1)

add_compile_options(-Werror -Wall -Wpedantic -Wconversion)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")

include_directories(${PROJECT_SOURCE_DIR})

add_executable(
    game
    src/main.cpp
    src/engine/Clock.cpp
    src/engine/Event.cpp
    src/engine/EventHandler.cpp
    src/engine/Game.cpp
    src/engine/time.cpp
)
