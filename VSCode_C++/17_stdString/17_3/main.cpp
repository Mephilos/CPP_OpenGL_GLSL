#include <iostream>
#include <string>

int main()
{
    //string 문자열에는 null이 없음
    std::string my_str("012345678");
    my_str.reserve(1000);
    
    std::cout << std::boolalpha;
    std::cout << my_str.empty() << std::endl;
    std::cout << my_str.size() << std::endl;
    std::cout << my_str.length() <<std::endl;
    std::cout << my_str.capacity() <<std::endl;
    std::cout << my_str.max_size() << std::endl;
    return 0;
}