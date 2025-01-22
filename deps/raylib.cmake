

find_package(raylib  QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    set(FETCHCONTENT_QUIET FALSE)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

    FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
    )

    FetchContent_MakeAvailable(raylib)



    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
        rlimgui
        GIT_REPOSITORY "https://github.com/raylib-extras/rlImGui.git"
        GIT_TAG "main"
        GIT_PROGRESS FALSE
    )

endif()