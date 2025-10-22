//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/10/25.
//

#include <iostream>



class Base
{
public:
    int m_i =0;
    
    virtual void print()
    {
        std::cout <<"I'm Base" << std::endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;
    
    virtual void print() override
    {
        std::cout <<"I'm derived" <<std::endl;
    }
};

void Someting(Base& b)
{
    b.print();
}
int main()
{
    Derived d;
    Base& b = d;
    
    b.print();
    
    return 0;
}
