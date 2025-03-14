#include <string>
#include <cstddef>
#include <iostream>
#include <locale>
#include <cstring>

int main(){
    {
        char* strHello = new char[7];
        strncpy(strHello, "hello!", sizeof(char) * 7);
        std::cout <<strHello << std::endl;
        
    }
}
