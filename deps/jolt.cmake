

find_package(JoltPhysics  QUIET) # QUIET or REQUIRED
if (NOT JoltPhysics_FOUND) # If there's none, fetch and build raylib

    FetchContent_Declare(
            JoltPhysics
            GIT_REPOSITORY "https://github.com/jrouwe/JoltPhysics"
            GIT_TAG "v5.2.0"
            SOURCE_SUBDIR "Build"
    )
    FetchContent_MakeAvailable(JoltPhysics)
endif()

