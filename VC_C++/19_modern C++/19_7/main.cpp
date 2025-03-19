#include <iostream>
#include <vector>
#include <utility>

using namespace std;


struct MyStruct
{};

void func(MyStruct& s)
{
    cout << "Pass by L-ref" <<endl;
}

void func(MyStruct&& s)
{
    cout << "Pass by R_ref" <<endl;
}

// void func(MyStruct s)
// {
//     cout << "Pass by Value" << endl;
// }

// template<typename T>
// void func_wrapper(T t)
// {
//     func(t);
// }

template<typename T>
void func_wrapper(T&& t)
{
    func(std::forward<T>(t));
}
int main()
{
    MyStruct s;

    func_wrapper(s);
    func_wrapper(MyStruct());

    // func(s);
    // func(MyStruct());
    
    return 0;
}