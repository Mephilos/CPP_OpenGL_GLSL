//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/4/25.
//


#include <iostream>


class Acc
{
private:
    int num = 0;
public:
    int& operator () (int acc)
    {
        return num+=acc;
    }
};


int main()
{
    Acc ac;
    
    std::cout<< ac(10) << std::endl;
    std::cout <<ac(30) << std::endl;
    return 0;
}
