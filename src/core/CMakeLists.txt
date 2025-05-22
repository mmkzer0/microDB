add_library(core
    mdb_config.h 
    mdb_core.c 
    mdb_core.h 
    mdb_data_types.c 
    mdb_data_types.h 
)

target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})