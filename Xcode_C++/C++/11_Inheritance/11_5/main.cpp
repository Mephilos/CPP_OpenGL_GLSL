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
    int m_public;
    int m_protected;
    int m_private;
};


class Derived : private Base//어떤걸로 받을지 지정
{
public:
    Derived()
    {
        
    }
};

class GrandChild : public Derived
{
    GrandChild()
    {
        
        // Derived 가 지정한 접근 지정자에 따라서 갈림
    }
};
int main()
{
    
    
    return 0;
}
