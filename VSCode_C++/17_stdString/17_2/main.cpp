#include <iostream>
#include <string>
#include <vector>
#include <sstream>


template <typename T>
std::string to_string(T x)
{
    std::ostringstream osstream;
    osstream << x;
    return osstream.str();
}

template <typename T>
bool FromString(const std::string& str , T& x)
{
    std::istringstream isstream(str);
    return (isstream >> x) ? true : false;
}

int main(){
    // std::string my_string("my string");
    
    // std::string second_string(my_string);
    
    // std::cout << second_string << std::endl;
    
    // std::vector<char> vec;
    // for( auto e : "Is good day to die")
    //     vec.push_back(e);

    //     std::string second_string(vec.begin(),std::find(vec.begin(),vec.end(), 'd'));
    
    //     std::cout << second_string << std::endl;
    
    std::string my_str(std::to_string(3));
    std::string my_str2(std::to_string(500000));
    std::string my_str3(std::to_string(3.141592));


    my_str += std::to_string(256);

    int i = std::stoi(my_str);
    float f = std::stof(my_str2);
    std::cout << my_str << std::endl;
    std::cout << i <<std::endl;
    std::cout << f <<std::endl;
    std::cout << my_str3 <<std::endl;



    std::string my_str4(to_string(3.14));

    double d;
    
    if(FromString(my_str4, d))
        std::cout << d << std::endl;
    else
        std::cout << "Cannot covert string to double" << std::endl;

    std::cout << my_str4 << std::endl;

    return 0;
}