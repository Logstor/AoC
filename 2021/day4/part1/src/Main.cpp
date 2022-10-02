#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <array>

#include "Config.h"

int main(int argc, char** argv)
{
    std::cout << "Hello world - This is version: " << day4_VERSION_MAJOR << "." << day4_VERSION_MINOR << std::endl;

    if (argc != 2) { std::cout << "Only takes one file input!" << std::endl; }

    const char* inputFileName = argv[1];

    std::cout << "Using input file: " << inputFileName << std::endl;

    // Open file
    FILE* file = fopen(inputFileName, "r");

    // Close file
    fclose(file);

    // Print result

    return 0;
}