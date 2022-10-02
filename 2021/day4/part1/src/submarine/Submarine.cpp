#include "Submarine.hpp"

unsigned int Submarine::Dive(const unsigned int amount)
{
    this->Depth += amount;
    return GetDepth();
}

unsigned int Submarine::Ascend(const unsigned int amount)
{
    this->Depth -= amount;
    return GetDepth();
}

unsigned int Submarine::Forward(const unsigned int amount)
{
    this->Pos += amount;
    return GetPos();
}