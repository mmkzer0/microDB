add_library(indexing
    index_core.c
    index_core.h
)

target_include_directories(indexing PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})