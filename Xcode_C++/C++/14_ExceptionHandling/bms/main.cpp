//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if(b==0)
        throw std::runtime_error("0으로 나눌수 없습니다.");
    return a / b;
}
int main(){
    try {
        int result = divide(10, 0);
        std::cout <<"결과: " <<result << std::endl;
    }
    
    catch (const std::runtime_error &e) {
        std::cerr <<"런타임 에러 발생: " << e.what() <<std::endl;
    }
    
    catch (...){
        std::cerr << "알 수 없는 예외 발생." << std::endl;
    }
    
    return 0;
}
