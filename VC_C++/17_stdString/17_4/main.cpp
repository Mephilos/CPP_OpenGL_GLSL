#include <iostream>
#include <vector>
#include <string>
#include <exception>

int main()
{
    std::string my_str("abcdefg");

    char buf[20];

    my_str.copy(buf, 5, 1);

    buf[5] = '\0';

    std::cout << buf << std::endl;

    // std::cout << my_str[0] << std::endl;
    // std::cout << my_str[3] << std::endl;
    
    // my_str[3] = 'Z';
    // std::cout << my_str[3] << std::endl;
    // std::cout << my_str <<std::endl;

    // try {
    //     //my_str[100] = 'X';
    //     my_str.at(100) = 'X';
    // }
    // catch(std::exception & e){
    //     std::cout<< e.what() << std::endl;
    // }
    // std::cout << my_str.c_str() <<std::endl;
    
    // const char *arr = my_str.c_str(); //my_str.data() 같음

    // std::cout << (int)arr[6] << std::endl;
    // std::cout << (int)arr[7] << std::endl;

    return 0;
}