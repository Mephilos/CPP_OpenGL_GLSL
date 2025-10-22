//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/10/25.
//

#include <iostream>


class A
{
    
};
class B1 : public A
{
    
};
class B2 : public A
{
    
};

class C : public B1, public B2
{
    //class A를 두번 상속하게됨(다이어몬드 상속)
};
int main()
{
    
    
    return 0;;
}
