#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <array>

#include "Config.h"
#include "CoordinateSet.h"

int main(int argc, char** argv)
{
    std::cout << "Hello world - This is version: " << day5_VERSION_MAJOR << "." << day5_VERSION_MINOR << std::endl;

    if (argc != 2) { std::cout << "Only takes one file input!" << std::endl; }

    const char* inputFileName = argv[1];

    std::cout << "Using input file: " << inputFileName << std::endl;

    // Open file
    std::ifstream input(inputFileName, std::ios_base::in);
    if (!input.is_open())
    {
        std::cout << "File couldn't be opened!" << std::endl;
        return 0;
    }

    // Read all coordinate sets
    std::vector<CoordinateSet*> sets;
    CoordinateSet* pSet; unsigned int count = 0;
    char lineBuf[20];
    while (input.getline(lineBuf, 20))
    {
        pSet = (CoordinateSet*) malloc(sizeof(CoordinateSet));

        // Read numbers and insert
        std::sscanf(
            lineBuf, 
            "%u,%u -> %u,%u", 
            &pSet->x1, &pSet->y1, &pSet->x2, &pSet->y2
        );

        // Insert into vector
        sets.push_back(pSet);

        ++count;
    }

    // Print what was read
    std::cout << "Read " << count << " sets" << std::endl;
    for (CoordinateSet* set : sets)
        std::cout << "x1: " << set->x1 << ", y1: " << set->y1 <<  ", x2: " << set->x2 << ", y2: " << set->y2 << std::endl;

    

    // Clean up
    for (CoordinateSet* set : sets) free(set);

    return 0;
}