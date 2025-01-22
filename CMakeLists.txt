project(HelloWorld)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std:c++20")


include(deps/imgui.cmake)
include(deps/raylib.cmake)
include(deps/raygui.cmake)
include(deps/rlimgui.cmake)
include(deps/ryml.cmake)
include(deps/box2d.cmake)
include(deps/jolt.cmake)



add_executable(rlgui src/main.cpp)
#target_include_directories(gui PUBLIC "src/cosmos")

#
# Header only way of including: And the include folder
# ${FETCHCONTENT_BASE_DIR} points to the fetched directory
#
# Include raygui directory
target_include_directories(rlgui SYSTEM PRIVATE "${FETCHCONTENT_BASE_DIR}/raygui-src/src")

#include_directories(igui ${SDL2_INCLUDE_DIRS})
target_link_libraries(rlgui PUBLIC  raylib rlimgui imgui ryml::ryml)


if (MSVC)
    target_compile_options(rlgui PRIVATE /W4)
else()
    target_compile_options(rlgui PRIVATE -Wall -Wextra -pedantic)
endif()


