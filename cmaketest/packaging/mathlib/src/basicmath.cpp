#include "basicmath.hpp"
#include "config/mathlib.hpp"
#include <iostream>

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

void GetVersion()
{
   std::cout << "LIB VERSION:" <<  VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << "." << VERSION_TWEAK << std::endl;
}