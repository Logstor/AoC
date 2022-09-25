#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <stdio.h>
#include <string.h>

#include "Config.h"
#include "Submarine.hpp"

int main(int argc, char** argv)
{
    std::cout << "Hello world - This is version: " << day2_VERSION_MAJOR << "." << day2_VERSION_MINOR << std::endl;

    if (argc != 2) { std::cout << "Only takes one file input!" << std::endl; }

    const char* inputFileName = argv[1];

    std::cout << "Using input file: " << inputFileName << std::endl;

    // Create Submarine
    Submarine sub("Sarah");

    // Open file
    FILE* file = fopen(inputFileName, "r");

    // Read each line
    char cmd[20];
    unsigned int amount;
    while(fscanf(file, "%s %u\n", cmd, &amount) != EOF)
    {
        // Check and update submarine
        if (strcmp(cmd, "forward") == 0)
            sub.Forward(amount);
        else if (strcmp(cmd, "up") == 0)
            sub.AimUp(amount);
        else if (strcmp(cmd, "down") == 0)
            sub.AimDown(amount);
        else
            std::cout << cmd << " wasn't recognized!" << std::endl;
    }

    std::cout << "The final calculated position for the Submarine, Sarah, is: " << sub.CalcRes() << std::endl;

    // Close file
    fclose(file);

    return 0;
}