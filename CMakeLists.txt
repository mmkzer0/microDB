cmake_minimum_required(VERSION 3.31)
project(microDB C)


# set c std
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
add_compile_options(-O2 -Wall -Wextra)

# Set project source directory
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

# add exec
add_executable(microDB ${SRC_DIR}/main.c)

# split cmake
add_subdirectory(${SRC_DIR}/cli)
add_subdirectory(${SRC_DIR}/core)
add_subdirectory(${SRC_DIR}/indexing)
add_subdirectory(${SRC_DIR}/parser)
add_subdirectory(tests)

# Include dirs for public headers
include_directories(BEFORE
    ${SRC_DIR}
)

# libraries
target_link_libraries(microDB
    cli
    core
    indexing
    parser
)

set(CPACK_PACKAGE_NAME microDB)
