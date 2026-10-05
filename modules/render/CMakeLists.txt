file(GLOB render_sources CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/*.h"
)

add_library(render STATIC
    ${render_sources}
)

target_include_directories(render
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(render
    PRIVATE
        raylib
        core
)