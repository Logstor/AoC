cmake_minimum_required(VERSION 3.22)

# Project name
project(day2 VERSION 2.0 LANGUAGES CXX)

# Add executeable
add_executable(day2 src/Main.cpp)

configure_file(headers/Config.h.in ../headers/Config.h)

# Compiler flags
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror -Wuninitialized -Weffc++")
endif()
add_compile_options(-Wall -Wextra)

# Source files
target_sources(day2 PRIVATE src/Main.cpp src/submarine/Submarine.cpp)

# Include files
target_include_directories(day2 PUBLIC headers)