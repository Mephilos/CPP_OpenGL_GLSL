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
    Fraction(int num = 0, int den = 1)
        : _numerator(num), _denominator(den)
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
int main()
{
    Fraction frac(3,5);
    
    Fraction fr_copy(frac);
    
    Fraction fr_copy2 = frac;//대입 연산자 아님 복사 초기화
    
    return 0;
}
