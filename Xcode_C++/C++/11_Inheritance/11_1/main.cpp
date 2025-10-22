//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/7/25.
//

#include <iostream>

class Mother
{
private:
    int _i;
public:
    
    void setValue(const int& i_in)
    {
        this->_i = i_in;
    }
    int getValue()
    {
        return _i;
    }
    
    void print()
    {
        std::cout<< _i <<std::endl;
    }
};

class Child : public Mother
{
    
};


int main()
{
    Mother mother;
    mother.setValue(1024);
    mother.print();
    
    Child child;
    child.setValue(64);
    child.print();
    
    return 0;
}
