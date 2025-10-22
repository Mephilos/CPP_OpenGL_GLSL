#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <span>

using namespace std;

class CustomVector
{
public:
    unsigned n_data =0;
    int* ptr = nullptr;

    CustomVector(const unsigned& _n_data, const int& _init = 0)
    {
        cout << "Constructor" <<endl;

        init(_n_data,_init);
    }
    CustomVector(CustomVector& l_input)
    {
        cout << "Copy constructor" << endl;

        init(l_input.n_data);

        for(unsigned i = 0; i < n_data; ++i)
            ptr[i] = l_input.ptr[i];
    }
    CustomVector(CustomVector&& r_input)
    {
        cout << "Move Constructor" << endl;

        n_data = r_input.n_data;
        ptr = r_input.ptr;

        r_input.n_data = 0;
        r_input.ptr = nullptr;
    }
    ~CustomVector()
    {
        delete[] ptr;
    }




    void init(const unsigned& _n_data, const int& _init =0 )
    {
        n_data = _n_data;
        ptr = new int[n_data];

        std::span<int> arr(ptr, n_data);
        
        for(int e : arr)
        {
            e = _init;
        }
    }
};
void something(CustomVector& vec)
{
    cout<< "pass by l ref" <<endl;
    CustomVector new_vec(vec);
}
void something(CustomVector&& vec)
{
    cout << "pass by r ref" << endl;
    CustomVector new_vec(std::move(vec));
}

template<typename T>
void somethingTemplate(T&& vec)
{
    something(std::forward<T>(vec));
}
int main()
{
    CustomVector myVec(10, 1024);
    CustomVector temp(myVec);
    //CustomVector moveVec(std::move(myVec));

    cout << myVec.n_data <<endl;
    return 0;
}