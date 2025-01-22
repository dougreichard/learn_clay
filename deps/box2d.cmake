
find_package(box2d  QUIET) # QUIET or REQUIRED
if (NOT box2d_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)

    include(FetchContent)

    FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG main
    )

    set(BOX2D_BUILD_UNIT_TEST OFF)
    set(BOX2D_BUILD_TESTBED OFF)

    FetchContent_MakeAvailable(box2d)
endif()