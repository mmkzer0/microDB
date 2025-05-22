add_library(cli
    cli_base.c 
    cli_base.h
)

target_include_directories(cli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})