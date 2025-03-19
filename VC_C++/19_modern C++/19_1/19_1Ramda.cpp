#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void goodbye (const string& s){
    cout << "Goodbye" << s << endl;
}

class Object{
public:
    void hello(const string& s)
    {
        cout << "Hello " << s << endl;
    }
};


int main()
{
    //lamda-introducer
    //lamda-parameter-declaration
    //lamda-return-type-clause
    //compound-statement

    auto func = [](const int& i) -> void { cout << "Hello, world!" <<endl;};

    func(123);

    [](const int& i) -> void { cout << "Hello, world!" <<endl;}(12);

    {
        string name = "Jack";
        [&]() {std::cout << name <<endl;} ();
    }

    vector<int> v;

    v.push_back(1);
    v.push_back(2);

    auto func2 = [](int val) {cout << val << endl;};
    // for_each(v.begin(), v.end(), func2);
    for_each(v.begin(), v.end(), [](int val) {cout << val << endl;});

    cout << []() -> int { return 1;} () <<endl;

    std::function<void(int)> func3 = func2;
    func3(123);
    
    std::function<void()>func4 = std::bind(func3, 456);
    func4();

    {
        Object instance;
        auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

        f(string("World"));
        f("World");

        auto f2 = std::bind(&goodbye, std::placeholders::_1);

        f2(string("World"));

    }
    return 0;
}