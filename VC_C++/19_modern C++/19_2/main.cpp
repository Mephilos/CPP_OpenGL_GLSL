#include <iostream>
#include <tuple>

using namespace std;

auto my_func() //auto my_func()
{
    return tuple (123, 456, 789, 101);
}

int main()
{   
    auto[a, b, c, d] = my_func(); //auto result = my_func();

    cout << a << " " << b << " " << c << " " << d << endl;

    //cout << get<0>(result) <<" " << get<1>(result) <<endl;

    return 0;
}