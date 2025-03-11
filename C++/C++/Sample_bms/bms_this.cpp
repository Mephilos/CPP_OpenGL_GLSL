
#include <iostream>

class Mother {
private:
    int _i;  // 멤버 변수 (Member variable / data member)

public:
    // 생성자: 값을 받아 멤버 변수 _i를 초기화합니다.
    Mother(int i_in) : _i(i_in) {}

    // setValue 함수:
    // 매개변수 이름과 멤버 변수 이름이 같을 때, 혼동을 피하기 위해 this->를 사용하여 현재 객체의 멤버 변수임을 명시합니다.
    void setValue(const int& i_in) {
        this->_i = i_in;
        // 위의 코드는 같은 의미로 _i = i_in; 라고 쓸 수 있지만, 이름 충돌 시 this->가 필요합니다.
    }

    // getValue 함수:
    // 보통 그냥 멤버 변수의 값을 반환해야 하는데, 예시에서는 현재 객체의 포인터(this)를 반환하려고 했던 것 같은데,
    // 올바른 방법은, 만약 자기 자신의 복사본을 반환하거나, 참조를 반환해야 한다면 아래와 같이 할 수 있습니다.
    // 여기서는 단순하게 _i 값을 반환하도록 수정합니다.
    int getValue() const {
        return _i;
    }

    // getPointer 함수:
    // 현재 객체의 주소를 반환합니다.
    // 반환형은 Mother* (pointer to Mother)
    Mother* getPointer() {
        return this;  // 현재 객체의 주소를 명시적으로 반환
    }

    // 예시: 메소드 체이닝을 위한 함수
    // 이 함수는 _i 값을 증가시키고, 자기 자신의 참조(*this)를 반환합니다.
    Mother& increment() {
        ++this->_i;
        return *this;  // *this를 반환하면 현재 객체에 대한 레퍼런스가 반환되어 연쇄 호출(method chaining)이 가능함
    }
};

int main() {
    Mother m(10);         // m._i = 10
    m.setValue(20);       // m._i를 20으로 설정. 이때 this->를 사용함. (값 20이 멤버 변수 _i에 저장됨)
    
    // 메소드 체이닝 실행: m.increment()는 m._i를 21로 바꾸고, 반환된 자기 참조로 다시 increment()가 호출되어 m._i가 22가 됨.
    m.increment().increment();
    
    // getValue()를 호출하여 m._i의 값을 출력
    std::cout << "Value: " << m.getValue() << std::endl;  // 출력: Value: 22

    // getPointer()를 사용하여 m 객체의 주소를 출력합니다.
    std::cout << "Address: " << m.getPointer() << std::endl;
    
    return 0;
}
