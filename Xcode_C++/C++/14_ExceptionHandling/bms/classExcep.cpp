//
//  classExcep.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>
#include <exception>
#include <string>

class MyException : public std::exception{
private:
    std::string message;
    
public:
    explicit MyException(const std::string &msg) : message(msg) {}
    
    
    
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};


int main(){
    try {
        throw MyException("내 사용자 정의 예외 발생");
    }
    
    catch(const MyException& ex) {
        std::cerr <<"caught MyException: " <<ex.what() << std::endl;
    }
    return 0;
}
