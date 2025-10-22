//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/4/25.
//

#include <iostream>
#include <cassert>
class IntList
{
private:
    int _list[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
public:
    int& operator[] (const int index)
    {
        assert(index >= 0);
        assert(index < 10);
     
        return _list[index];
    }
    
    //컨스트(상수)로 값을 받아서 값을 바꿀수 없는경우 이렇게 읽는 건 가능하게 해줄 수 있음.
    const int& operator[] (const int index) const
    {
        assert(index >= 0);
        assert(index < 10);
     
        return _list[index];
    }
};

int main()
{
    IntList my_list;
    
    std::cout << my_list[3] << std::endl;;
    return 0;
}
