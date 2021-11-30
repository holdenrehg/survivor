cmake_minimum_required(VERSION 3.17)

project(Survivor VERSION 0.1)

find_package(raylib 3.0 QUIET)

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)

    FetchContent_Declare(
        raylib
       URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

        # build raylib
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

add_compile_options(-Werror -Wall -Wpedantic -Wconversion)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,--no-undefined")

include_directories(${PROJECT_SOURCE_DIR})

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/engine/Clock.cpp
    src/engine/Event.cpp
    src/engine/EventHandler.cpp
    src/engine/Game.cpp
    src/engine/time.cpp
    src/scenes/MainMenuScene.cpp
)

target_link_libraries(${PROJECT_NAME} raylib)
