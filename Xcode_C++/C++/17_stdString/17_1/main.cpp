//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/13/25.
//
#include <string>
#include <cstddef>
#include <iostream>
#include <locale>


int main(){
    {
        char* strHello = new char[7];
        strncpy(strHello, "hello!", sizeof(char) * 7);
        std::cout <<strHello << std::endl;
    }
}
