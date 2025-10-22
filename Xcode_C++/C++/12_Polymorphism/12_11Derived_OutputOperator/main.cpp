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
    Base() {}
    //friend는 맴버 함수가 아님. 직접 오버라이딩 안됨.
    friend std::ostream& operator <<(std::ostream& out, const Base& b)
    {
        return b.print(out);
    }
    
    virtual std::ostream& print(std::ostream& out) const
    {
        out<< "Base";
        return out;
    }
};

class Derived : public Base
{
public:
    Derived(){}
    
    virtual std::ostream& print(std::ostream& out) const override
    {
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b;
    std::cout <<b << '\n';
    
    Derived d;
    std::cout<< d << '\n';
    
    Base& bref = d;
    std::cout << bref << '\n';
    
    
    return 0;
}
