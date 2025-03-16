//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/14/25.
//

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    char buf [4];
    std::cin.get(buf,4);
    std::cout <<std::cin.gcount() << " " << buf <<std::endl;
    std::cin.getline(buf,4);
    std::cout <<std::cin.gcount() << " " << buf <<std::endl;
    std::cin.get(buf,4);
    std::cout <<std::cin.gcount() << " " << buf <<std::endl;
    
    return 0;
}
