//
//  inheritanceExample.h
//  C++
//
//  Created by TAEHO SIM on 3/7/25.
//
#ifndef InheritanceExample_h
#define InheritanceExample_h



#include <iostream>
#include <string>


//기반 클래스 base class 동물의 기본 특성과 기능을 정의 하는 기반 클래스
class Animal{
protected:
    std::string _name;
    
public:
    //생성자 동물의 이름을 초기화.
    Animal(const std:: string& n);
    
    
    //가상함수(virtual function): 동물이 내는 소리를 출력하는 함수.
    // 파생 클래스에서 이 함수를 오버라이딩 하여 각 동물 고유의 소리를 구현합니다.
    virtual void speak() const;
    //가상 소멸자(Virtual Destructor): 파생 클래서 객체의 소멸 시 올바른 소멸자가 호출되도록 보장
    virtual ~Animal();
};



//파생 클래스 개(Dog)

//dog는 Animal class 에서 public을 상속 받아 모든 public/ protected 멤버를 그대로 물려 받습니다.
class Dog : public Animal {
public:
    //Dog 생성자 : Animal 생성자를 호출하여 이름을 초기화합니다.
    Dog(const std::string& n);
    
    //speak 함수 오버라이딩: dog고유의 소리 "woof!" 출력
    void speak() const override;
    
};

class Cat : public Animal {
public:
    Cat(const std::string& n);
    
    //고양이 소리 출력
    void speak() const override;
};



//다중 상속 예시

//여러 기반 클래스에서 상속받는 경우도 있음

class Bird{
public:
    virtual void fly() const{
        std::cout << "Bird is flying" << std::endl;
    }
    virtual ~Bird() {}
};

class Colorful {
public:
    virtual void showColor() const {
    //    std::cout << "Colorful display" <<std::endl;
    }
    virtual ~Colorful() {}
};

class Flamingo : public Bird, public Colorful {
public:
    void fly() const override {
        std::cout << "Flamingo flutters with style" <<std::endl;
    }
    
    void showColor() const override {
        std::cout << "Flamingo shows vibrant pink color." << std::endl;
    }
};



#endif /* inheritanceExample_h */
