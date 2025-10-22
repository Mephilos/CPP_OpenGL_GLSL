#include <iostream>


class Example
{
private:
    int value;
public:
    Example(int val = 0) : value(val) {}
    
    Example& operator++();
    Example operator++(int);
    
    void print() const
    {
        std::cout << "Value: " << value <<std::endl;
    }
};

Example& Example::operator++()
{
    ++value;
    return * this;
}
Example Example::operator++(int)
{
    Example temp = *this;
    ++value;
    return temp;
}

int main()
{
    Example ex(5);
    
    ++ex;
    ex.print();
    
    ex++;
    ex.print();
    return 0;
}
