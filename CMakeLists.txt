project(claygui)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std:c++20")



include(deps/raylib.cmake)
include(deps/clay.cmake)

add_executable(claygui src/main.cpp)
#target_include_directories(gui PUBLIC "src/cosmos")

#
# Header only way of including: And the include folder
# ${FETCHCONTENT_BASE_DIR} points to the fetched directory
#
# Include raygui directory
target_include_directories(claygui SYSTEM PRIVATE "${FETCHCONTENT_BASE_DIR}/clay-src")

#include_directories(igui ${SDL2_INCLUDE_DIRS})
target_link_libraries(claygui PUBLIC  raylib)


if (MSVC)
    target_compile_options(claygui PRIVATE /W4)
else()
    target_compile_options(claygui PRIVATE -Wall -Wextra -pedantic)
endif()


