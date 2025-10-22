//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/10/25.
//

#include <iostream>
class A
{
public:
    void print()
    {
        std::cout<< "A" << std::endl;
    }
    virtual A* getThis()
    {
        std::cout << "A::getThis()" <<std::endl;
        return this;
    }
};

class B : public A
{
public:
    void print()
    {
        std::cout <<"B"<< std::endl;
    }
    virtual B* getThis()
    {
        std::cout << "B::getThis()" <<std::endl;
        return this;
    }
};



int main()
{
    
    A a;
    B b;
    
    A& ref = b;
    b.getThis()->print();
    ref.getThis()->print();
    
    std::cout<< typeid(b.getThis()).name() <<std::endl;
    std::cout<< typeid(ref.getThis()).name() <<std::endl;
    return 0;
}
