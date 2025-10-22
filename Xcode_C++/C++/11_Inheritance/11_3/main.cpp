//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/10/25.
//

#include <iostream>
#include <vector>

class Mother{
private:
protected:
public:
    int m_i;
};

class Child  : public Mother{
public:
    Child()
    {
        
    }
};
// 생성될때 베이스 클래스가 먼저 생성이되고, Derived class 가 나중에 생성됨.
