add_library(parser
    tokenize.c 
    tokenize.h
)

target_include_directories(parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})