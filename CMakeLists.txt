cmake_minimum_required(VERSION 3.25.1)
project(AudioGen)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

# =========== main executable ========== #
file(GLOB All_Sources CONFIGURE_DEPENDS "src/*.cpp" )
add_executable(AudioGen)
target_sources(AudioGen
    PRIVATE
        ${All_Sources}
)

# ========= External Libraries ========= #
include(FetchContent)
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) 
FetchContent_MakeAvailable(raylib)

target_link_libraries(AudioGen
    PRIVATE
        raylib
)

# ============== modules ============== #
add_subdirectory(modules/core)
add_subdirectory(modules/render)

target_link_libraries(AudioGen
    PRIVATE
        core
        render
)