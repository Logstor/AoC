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
#include "VentMap.h"

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
    CoordinateSet* pSet; unsigned int count = 0, xMax = 0, yMax = 0;
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

        if (pSet->x1 > xMax) xMax = pSet->x1;
        if (pSet->x2 > xMax) xMax = pSet->x2;
        if (pSet->y1 > yMax) yMax = pSet->y1;
        if (pSet->y2 > yMax) yMax = pSet->y2;

        // Insert into vector
        sets.push_back(pSet);

        ++count;
    }

    // Print what was read
    std::cout << "Read " << count << " sets | " << "xMax: " << xMax << ", yMax: " << yMax << std::endl;
    count = 0;
    for (CoordinateSet* set : sets)
    {
        ++count;
        std::cout << count << " | x1: " << set->x1 << ", y1: " << set->y1 <<  ", x2: " << set->x2 << ", y2: " << set->y2 << std::endl;
    }

    // Put the coordinate sets in Map
    VentMap hydrothermalMap(xMax + 1, yMax + 1);
    hydrothermalMap.putCoordinateSets(sets);

    // 
    // std::cout << '\n' << hydrothermalMap.toString() << '\n' << std::endl;

    // Print overlapping points
    std::cout << "Overlapping points: " << hydrothermalMap.overlappingPoints() << std::endl;

    // Clean up
    for (CoordinateSet* set : sets) free(set);

    return 0;
}