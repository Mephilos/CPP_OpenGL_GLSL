//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>
#include <exception>
#include <string>

class CustomException : public std::exception{
public:
    const char* what() const noexcept override{
        return "Custom exception";
    }
};
int main(){
    try {
        //        std::string s;
        //        s.resize(-1);
        throw CustomException();
    }
    
    catch (std::exception& exception){
        std::cout << typeid(exception).name() << std::endl;
        std::cerr<<exception.what() <<std::endl;
    }
    return 0;
}
