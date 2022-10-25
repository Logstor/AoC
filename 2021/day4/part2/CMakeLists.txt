cmake_minimum_required(VERSION 3.22)

# Project name
project(day4 VERSION 2.0 LANGUAGES CXX)

# Add executeable
add_executable(day4 src/Main.cpp)

configure_file(headers/Config.h.in ../headers/Config.h)

# Compiler flags
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror -Wuninitialized -ggdb3 -O0")
endif()

# Source files
target_sources(day4 PRIVATE src/Main.cpp src/bingo/Board.cpp src/bingo/Bingo.cpp)

# Include files
target_include_directories(day4 PUBLIC headers headers/bingo)