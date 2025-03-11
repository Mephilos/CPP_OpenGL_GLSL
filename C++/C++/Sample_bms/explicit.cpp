//
//  explicit.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>
#include <string>

class MyString {
private:
    std::string data;
public:
    // explicit 키워드: 단일 인자 생성자가 암시적으로 사용되지 않게 만듭니다.
    explicit MyString(const std::string &s) : data(s) {}

    void print() const {
        std::cout << data << std::endl;
    }
};

void printString(const MyString& s) {
    s.print();
}

int main() {
    // printString("Hello, world!"); // 오류 발생: 암시적 변환이 금지됨.
    // 따라서, 다음과 같이 명시적으로 변환하여 사용해야 함:
    
    MyString ms("Wow");
    
    ms.print();
    printString(MyString("Hello, world!"));
    
    return 0;
}
