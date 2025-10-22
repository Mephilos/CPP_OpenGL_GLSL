//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/4/25.
//


#include <iostream>
#include <cassert>

class Fraction
{
private:
    int _numerator;
    int _denominator;
    
public:
    // 자동 컨버전 되거나 케스팅 되는걸 방지하기 위해서 delete, explicit를 사용함

    Fraction(char) = delete; //char로 받는걸 제한하는 delete방식
    explicit Fraction(int num = 0, int den = 1) : _numerator(num), _denominator(den)
    {
        assert(den !=0);
    }

    
    Fraction(const Fraction& fraction)
        : _numerator(fraction._numerator), _denominator(fraction._denominator)
    {
        std::cout << "Copy constructor called" <<std::endl;
    }
    
    friend std::ostream& operator << (std::ostream& out, const Fraction& f)
    {
        std::cout<< f._numerator << " / " << f._denominator <<std::endl;
        return out;
    }
    
};

void Something(Fraction frac)
{
    std::cout <<frac<<std::endl;
}
int main()
{
    Fraction frac(3,5);
    
    Fraction fr_copy(frac);
    
    Fraction fr_copy2 = frac;//대입 연산자 아님 복사 초기화
    
//    Fraction fr_char('A');delete 명령어로 막힘
//    Something(7); explicit 명령어로 변환이 막힘
    
    return 0;
}
