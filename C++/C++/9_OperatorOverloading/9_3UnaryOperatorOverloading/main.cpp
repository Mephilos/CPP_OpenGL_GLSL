//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/3/25.
//

#include <iostream>

class Cents
{
private:
    int _cents;
public:
    Cents(int cents = 0)
    :_cents(cents) {}
    
//    int getCents() const
//    {
//        std::cout << "상수형" <<std::endl;
//        return _cents;
//    }
//    int& getCents()
//    {
//        std::cout << "참조형" <<std::endl;
//        return _cents;
//    }
    Cents operator - () const
    {
        return Cents(-_cents);
    }
    bool operator ! () const
    {
        return (_cents == 0) ? true : false;
    }
    friend std::ostream& operator << (std::ostream& out, const Cents &cents)
    {
        out << cents._cents;
        return out;
    }
    
//    void print()
//    {
//        std::cout << getCents() <<std::endl;
//    }
};


int main()
{
    
    
    Cents cents1(6);
    Cents cents2(0);
    
    std::cout << !cents1 << " " << !cents2 <<std::endl;
    
    return 0;
}
