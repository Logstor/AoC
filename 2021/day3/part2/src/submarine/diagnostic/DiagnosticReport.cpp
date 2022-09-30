#include "DiagnosticReport.hpp"

#include <iostream>
#include <string>
#include <stdlib.h>

DiagnosticReport::PowerPair* DiagnosticReport::FindPowerStringPair(const unsigned int bitLength)
{
    // Result string
    PowerPair* pair = (PowerPair*) malloc(sizeof(PowerPair));

    // For every column
    unsigned int zero, one;
    char currBit;
    for (unsigned int i=0; i < bitLength; ++i)
    {
        // Reset
        zero = one = 0;

        // Go through every bit row
        for (BitSeq row : this->InputBits)
        {
            currBit = row.bits[i];

            // Check what kind
            if (currBit == '1')
                ++one;
            else if (currBit == '0')
                ++zero;
            else
                std::cout << "Error! Bit now recognized: " << currBit << std::endl;
        }

        // Set the bit
        if (zero > one)
        {
            pair->gamma[i] = '0';
            pair->epsilon[i] = '1';
        }
        else
        {
            pair->gamma[i] = '1';
            pair->epsilon[i] = '0';
        }
    }

    return pair;
}

int32_t DiagnosticReport::FindOxygenGenRating() const
{
    // Init starting vector
    std::vector<const BitSeq*> currRows;
    currRows.reserve(this->InputBits.size());
    for (const BitSeq& row : this->InputBits)
    {
        currRows.push_back(
            &row
        );
    }

    // Keep eliminating Bit rows
    unsigned int currBitPos = 0; char currMostCommon;
    do 
    {
        // Find most common
        currMostCommon = this->FindMostCommonBit(currBitPos, currRows);

        // Eliminate
        std::vector<BitSeq const*> nRows; nRows.reserve(currRows.size());

        if (currMostCommon == '=')
        {
            for (BitSeq const* row : currRows)
            {
                if (row->bits[currBitPos] == '1') nRows.push_back(row);
            }
        }
        else
        {
            for (BitSeq const* row : currRows)
            {
                if (row->bits[currBitPos] == currMostCommon) nRows.push_back(row);
            }
        }

        // Increment and set curr
        currRows = nRows;
        ++currBitPos;
    } 
    while (currRows.size() > 1);

    char* end;
    return strtoul(currRows[0]->bits, &end, 2);
}

int32_t DiagnosticReport::FindScrubRating() const
{
    // Init starting vector
    std::vector<const BitSeq*> currRows;
    currRows.reserve(this->InputBits.size());
    for (const BitSeq& row : this->InputBits)
    {
        currRows.push_back(
            &row
        );
    }

    // Keep eliminating Bit rows
    unsigned int currBitPos = 0; char currLeastCommon;
    do 
    {
        // Find most common
        currLeastCommon = this->FindLeastCommonBit(currBitPos, currRows);

        // Eliminate
        std::vector<BitSeq const*> nRows; nRows.reserve(currRows.size());

        if (currLeastCommon == '=')
        {
            for (BitSeq const* row : currRows)
            {
                if (row->bits[currBitPos] == '0') nRows.push_back(row);
            }
        }
        else
        {
            for (BitSeq const* row : currRows)
            {
                if (row->bits[currBitPos] == currLeastCommon) nRows.push_back(row);
            }
        }

        // Increment and set curr
        currRows = nRows;
        ++currBitPos;
    } 
    while (currRows.size() > 1);

    char* end;
    return strtoul(currRows[0]->bits, &end, 2);    
}

char DiagnosticReport::FindMostCommonBit(const unsigned position, std::vector<const BitSeq*> bitRows) const
{
    // Loop through and count
    unsigned int zero = 0, one = 0;
    for (const BitSeq* row : bitRows)
    {
        (row->bits[position] == '1') ? ++one : ++zero;
    }

    // Return depending on stat
    if (zero > one) return '0';
    else if (zero < one) return '1';
    else return '=';
}

char DiagnosticReport::FindLeastCommonBit(const unsigned int position, std::vector<const BitSeq*> bitRows) const
{
    // Loop through and count
    int accum = 0;
    for (const BitSeq* row : bitRows)
    {
        (row->bits[position] == '1') ? ++accum : --accum;
    }

    // Return depending on stat
    if (accum > 0) return '0';
    else if (accum < 0) return '1';
    else return '=';
}

void DiagnosticReport::Analyze()
{
    const unsigned int bitLength = this->InputBits[0].length;

    PowerPair* pair = FindPowerStringPair(bitLength);

    // Convert to ints
    char* end;
    this->GammaRate = strtoul(pair->gamma, &end, 2);
    this->EpsilonRate = strtoul(pair->epsilon, &end, 2);
    this->CO2ScrubRating = this->FindScrubRating();
    this->OxygenGenRating = this->FindOxygenGenRating();

    // Clean up
    free(pair);

    this->Analyzed = true;
}

uint32_t DiagnosticReport::CalcPowerConsumption() const
{
    return (uint32_t) (this->EpsilonRate * this->GammaRate);
}

uint32_t DiagnosticReport:: CalcLifeSupportRating() const
{
    return (uint32_t) (this->CO2ScrubRating * this->OxygenGenRating);
}
