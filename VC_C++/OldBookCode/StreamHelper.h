#pragma once

#include "Account.h"
#include <limits>

void cinClear()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void stripNewlines()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}