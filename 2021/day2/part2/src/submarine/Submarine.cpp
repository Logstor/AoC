#include "Submarine.hpp"

unsigned int Submarine::AimDown(const unsigned int amount)
{
    this->Aim += amount;
    return GetDepth();
}

unsigned int Submarine::AimUp(const unsigned int amount)
{
    this->Aim -= amount;
    return GetDepth();
}

unsigned int Submarine::Forward(const unsigned int amount)
{
    this->Pos += amount;
    this->Depth += this->Aim * amount;
    return GetPos();
}