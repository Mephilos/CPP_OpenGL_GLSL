//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/3/25.
//

#include <iostream>

class Counter
{
private:
    int value;
    
public:
    Counter(int val = 0) : value(val) {}
    
    Counter& operator++()
    {
        ++value;
        return* this;
    }
    
    Counter operator++(int)
    {
        Counter temp = *this;
        ++(*this);
        return temp;
    }
    
    int getValue() const
    {
        return value;
    }
};

int main()
{
    Counter count(5);
    
    std:: cout << "Initial value: " << count.getValue() <<std::endl;
    
    ++count;
    
    std::cout << "After prefix increment: " << count.getValue() << std::endl;
    
    count++;
    
    std::cout << "After postfix increment: " << count.getValue() << std::endl;
    
    return 0;
}
