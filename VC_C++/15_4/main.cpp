//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#include "Resource.h"
#include "AutoPtr.h"
#include <utility>
#include <vector>
#include <string>

template<class T>
void MySwap(T& a, T& b){
    // T temp = a;
    // a = b;
    // b = temp;

    T temp{std::move(a)}; // 초기화 
    a = std::move(b);
    b = std::move(temp);
}

int main(){
    {
        AutoPtr<Resource> res1(new Resource(10000));
        
        std::cout <<res1.m_ptr <<std::endl;
        
        AutoPtr<Resource> res2 = std::move(res1);
        
        std::cout <<res1.m_ptr<<std::endl;
        std::cout <<res2.m_ptr<<std::endl;
    }
    
    {
        AutoPtr<Resource> res1(new Resource(3));
        res1->setAll(3);
        AutoPtr<Resource> res2(new Resource(5));
        res2->setAll(5);

        MySwap(res1, res2);

        res1->print();
        res2->print();
    }

    {
        std::vector<std::string> v;
        std::string str = "Hello";

        v.push_back(str);

        std::cout << str << std::endl;
        std::cout << v[0] << std::endl;

        v.push_back(std::move(str));

        std::cout << str <<std::endl;
        std::cout <<v[0] << " " << v[1] <<std::endl;
    }

    {
        std::string x = "World";
        std::string y = "C++";

        MySwap(x, y);

        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    }
    
    
    return 0;
}
