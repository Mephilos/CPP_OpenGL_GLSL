//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/10/25.
//

#include <iostream>
template<typename T>
T getMax(T x, T y)
{
    return (x>y) ? x:y;
}
template<>//템플릿 특수화 char(자료형)을 사용할때 이 템플릿을 사용하라는 뜻.
char getMax(char x, char y)
{
    std::cout<< "Warning : comparing chars" << std::endl;
    
    return (x > y) ? x:y;
}

int main()
{
    std::cout << getMax('a' , 'b') <<std::endl;
    std::cout << getMax(1, 2) << std::endl;
    std::cout << getMax(3.14, 1.592) << std::endl;
    std::cout << getMax(1.0f, 3.4f) << std::endl;
    std::cout << getMax('a','c') <<std::endl;
    
    return 0;
}
