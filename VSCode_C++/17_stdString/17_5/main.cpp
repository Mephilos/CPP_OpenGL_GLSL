#include <string>
#include <vector>
#include <iostream>


int main()
{  
    std::string str1("one");

    std::string str2;

    str2.assign(std::move(str1)) ;
    
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    
    return 0;
}