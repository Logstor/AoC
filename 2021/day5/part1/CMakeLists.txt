cmake_minimum_required(VERSION 3.22)

# Project name
project(day5 VERSION 1.0 LANGUAGES CXX)

# Add executeable
add_executable(day5 src/Main.cpp)

configure_file(headers/Config.h.in ../headers/Config.h)

# Compiler flags
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror -Wuninitialized -ggdb3 -O0")
endif()

# Source files
target_sources(day5 PRIVATE src/Main.cpp src/array/Array.cpp src/array/Array2D.cpp)

# Include files
target_include_directories(day5 PUBLIC headers headers/array)