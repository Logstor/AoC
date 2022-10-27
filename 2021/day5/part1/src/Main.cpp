#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <array>

#include "Config.h"

int main(int argc, char** argv)
{
    std::cout << "Hello world - This is version: " << day5_VERSION_MAJOR << "." << day5_VERSION_MINOR << std::endl;

    if (argc != 2) { std::cout << "Only takes one file input!" << std::endl; }

    const char* inputFileName = argv[1];

    std::cout << "Using input file: " << inputFileName << std::endl;

    // Open file
    std::fstream input(inputFileName, std::ios_base::in);
    if (!input.is_open())
    {
        std::cout << "File couldn't be opened!" << std::endl;
        return 0;
    }



    return 0;
}