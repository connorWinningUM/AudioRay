file(GLOB core_sources CONFIGURE_DEPENDS 
    "${CMAKE_CURRENT_LIST_DIR}/*.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/*.h"
)

add_library(core STATIC
    ${core_sources}
)

target_link_libraries(core
    PUBLIC
        raylib
)

target_include_directories(core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)