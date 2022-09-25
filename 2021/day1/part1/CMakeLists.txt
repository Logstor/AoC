cmake_minimum_required(VERSION 3.22)

# Project name
project(day1 VERSION 1.0)

# Add executeable
add_executable(day1 src/Main.cpp)

configure_file(src/headers/Config.h.in ../src/headers/Config.h)

# Include files
target_include_directories(day1 PUBLIC ${PROJECT_BINARY_DIR})