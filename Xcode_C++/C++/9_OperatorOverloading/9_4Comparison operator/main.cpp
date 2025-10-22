//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/4/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <random>

class Cents
{
private:
    int _cents;
public:
    Cents(int cents = 0)
    :_cents(cents) {}
    
    int getCents() const
    {
        std::cout << "상수형" <<std::endl;
        return _cents;
    }
    int& getCents()
    {
        std::cout << "참조형" <<std::endl;
        return _cents;
    }
    Cents operator - () const
    {
        return Cents(-_cents);
    }
    bool operator ! () const
    {
        return (_cents == 0) ? true : false;
    }
    
    
    friend bool operator == (const Cents& c1, const Cents& c2)
    {
        return c1._cents == c2._cents;
    }
    bool operator != (const Cents& otherOne) const
    {
        return _cents != otherOne._cents;
    }
    
    friend std::ostream& operator << (std::ostream& out, const Cents &cents)
    {
        out << cents._cents;
        return out;
    }
    friend bool operator < (const Cents &c1, const Cents &c2)
    {
        return c1._cents < c2._cents;
    //  return c1._cents > c2._cents; 이경우 정렬이 큰숫자부터 됨(반대로 되는것) 근데 실제로 이렇게 쓰면 버그가 날수도 있음
    }
    
};


int main()
{
    std::vector<Cents> arr(20);
    for(unsigned i = 0; i < 20 ; ++i)
    {
        arr[i].getCents() = i;
    }
    
    
    std::random_device rd;
    std::mt19937_64 g(rd());
    std::shuffle(arr.begin(), arr.end(), g);
    
    for(auto &element : arr)
    {
        std::cout << element << " ";
    }
    std::cout<<std::endl;
    
    
    std::sort(std::begin(arr), std::end(arr));
    
    for(auto &element : arr)
    {
        std::cout << element << " ";
    }
    std::cout<<std::endl;
    
    return 0;
}
