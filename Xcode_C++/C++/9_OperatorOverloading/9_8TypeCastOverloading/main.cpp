#include <iostream>

// 전방 선언은 그대로 유지합니다.
class Cents;

class Dollar {
private:
    double _dollars = 0;
    
public:
    Dollar(const double& input) : _dollars(input) {}

    // Dollar -> Cents 형변환 멤버 함수 (멤버 함수이므로 접근 가능)
    operator Cents();

    double getDollars() const {
        return _dollars;
    }
};

// Cents 클래스의 정의
class Cents {
private:
    int _cents;
    
public:
    Cents(int cents = 0) : _cents(cents) {}

    // 상수형 getter (출력용)
    int getCents() const {
        // "상수형" 메시지는 디버깅 목적으로 출력하는 예제라 필요에 따라 제거할 수 있음
        std::cout << "상수형" << std::endl;
        return _cents;
    }
    
    // 참조형 getter (출력용은 주로 위의 상수형 getter를 사용)
    int& getCents() {
        std::cout << "참조형" << std::endl;
        return _cents;
    }
    
    Cents operator - () const {
        return Cents(-_cents);
    }
    
    bool operator ! () const {
        return (_cents == 0);
    }
    
    // Dollar로의 형변환 멤버 함수
    operator Dollar() {
        return Dollar(_cents * 0.01);
    }
    
    // 다른 연산자들은 그대로 유지
    operator int() {
        return _cents;
    }
};

// 멤버 함수 Dollar::operator Cents() 정의
Dollar::operator Cents() {
    // Dollar의 private 멤버 _dollars에 직접 접근은 가능 (멤버 함수이므로)
    return Cents(static_cast<int>(_dollars * 100));
}

// friend 없이 operator<<를 외부에서 정의

// Dollar에 대한 출력 연산자(<<) 정의: public getter getDollars() 사용
std::ostream& operator << (std::ostream& out, const Dollar& dollar) {
    out << dollar.getDollars() << " dollars";
    return out;
}

// Cents에 대한 출력 연산자(<<) 정의: public getter getCents() 사용
std::ostream& operator << (std::ostream& out, const Cents& cents) {
    // getCents() 호출 시 "상수형" 메시지가 출력될 수 있으므로, 만약 메시지를 원치 않는다면 별도의 출력 전용 getter를 만들어 사용하세요.
    out << cents.getCents();
    return out;
}

void printInt (const int& value) {
    std::cout << value << std::endl;
}

int main() {
    Dollar do1(2);
    
    // Dollar에서 Cents로 형변환 (멤버 함수 operator Cents() 사용)
    Cents cents = do1;
    
    Cents cents1(6);
    Cents cents2(0);
    
    // Cents에서 Dollar로 형변환하여 출력 (멤버 함수 operator Dollar() 사용)
    Dollar dollarFromCents = cents1;
    std::cout << "Dollar from Cents: " << dollarFromCents << std::endl;
    
    std::cout << !cents1 << " " << !cents2 << std::endl;
    
    printInt(cents);
    
    return 0;
}
