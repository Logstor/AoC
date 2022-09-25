cmake_minimum_required(VERSION 3.22)

# Project name
project(day3 VERSION 1.0 LANGUAGES CXX)

# Add executeable
add_executable(day3 src/Main.cpp)

configure_file(headers/Config.h.in ../headers/Config.h)

# Compiler flags
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror -Wuninitialized -Weffc++")
endif()

# Source files
target_sources(day3 PRIVATE src/Main.cpp src/submarine/Submarine.cpp src/submarine/diagnostic/DiagnosticReport.cpp)

# Include files
target_include_directories(day3 PUBLIC headers headers/submarine headers/submarine/diagnostic)