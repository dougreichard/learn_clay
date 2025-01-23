

find_package(clay  QUIET) # QUIET or REQUIRED
if (NOT clay_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    set(FETCHCONTENT_QUIET FALSE)
    FetchContent_Declare(
        clay
        GIT_REPOSITORY "https://github.com/nicbarker/clay.git"
        GIT_TAG "main"
        GIT_PROGRESS TRUE
    )
    #FetchContent_MakeAvailable(clay)
    #FetchContent_MakeAvailable(clay)
    # Populate gets it from git hub,
    # but doesn't build CLAY cmake, 
    # builds a bunch of examples
    # Just need the source
    FetchContent_Populate(clay)

endif()