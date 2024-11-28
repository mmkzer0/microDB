cmake_minimum_required(VERSION 3.31)
project(microDB C)

# c std
set(CMAKE_C_STANDARD 17)

# add exec
add_executable()

# split cmake
add_subdirectory(src)
add_subdirectory(tests)

# libraries
add_library()
include_directories(src)
