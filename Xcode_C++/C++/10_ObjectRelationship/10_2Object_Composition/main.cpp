//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/5/25.
//
#include "monster.h"


int main()
{
    Monster mob1("Sanson", Position2D(0,0));
    
    std::cout << mob1 << std::endl;
    
    {
        mob1.moveTo(Position2D(1, 1));
        
        std::cout << mob1 <<std::endl;
    }
    
    
    return 0;
}
