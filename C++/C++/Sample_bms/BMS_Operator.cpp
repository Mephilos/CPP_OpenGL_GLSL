//
//  BMS_Operator.cpp
//  C++
//
//  Created by TAEHO SIM on 3/9/25.
//
#include <algorithm>
#include <iostream>
#include <vector>


struct Linear{

    double a, b;
    
    double operator()(double x) const{
        return a * x + b;
    }
    
};
int main(){
    Linear f {2, 1};
    Linear g {-1, 0};
    
    double f_0 = f(0);
    double f_1 = f(1);
    
    double g_0 = g(0);
    
    
    std::cout << f_0 << std::endl;
    std::cout << f_1 << std::endl;
    std::cout << g_0 << std::endl;
}
