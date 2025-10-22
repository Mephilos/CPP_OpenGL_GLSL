#include <iostream>
#include <stdexcept>


class Robot {
private:
    int* parts;
    
public:
    Robot(int numParts) try
    : parts(new int[numParts]) {
        if(numParts <= 0)
            throw std::runtime_error("부품 개수가 0 보다 커야 합니다!");
        std::cout<<"Robot생성자: 부품 할당 완료" <<std::endl;
    }
    catch(const std::exception& e) {
        std::cerr<< "Robot 생성자에서 오류 발생: " <<e.what() << std::endl;
    
      //  throw;
    }
    
    ~Robot(){
        delete [] parts;
        std::cout <<"Robot 소멸자: 부품 해제" << std::endl;
    }
};

int main(){

    try{
        Robot r1(5);
        
        Robot r2(0);
    }
    catch(...) {
        std::cerr <<"main: 예외가 발생하여 프로그램을 종료합니다." << std::endl;
    }
    return 0;
}

