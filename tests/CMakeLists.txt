add_library(tests
    test_tablecheck.c
)

target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})