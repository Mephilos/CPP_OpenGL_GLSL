//
//  InheritanceExample.cpp
//  C++
//
//  Created by TAEHO SIM on 3/7/25.
//

#include "InheritanceExample.h"


Animal::Animal(const std::string& name) : _name(name) {}

void Animal::speak() const {
    std::cout <<"Animal speaks" <<std::endl;
}

Animal::~Animal(){}


Dog::Dog(const std::string& name) : Animal(name) {}

void Dog::speak() const {
    std::cout << _name << "say: Woof!" << std::endl;
}


Cat::Cat(const std::string& name) : Animal(name) {}

void Cat::speak() const{
    std::cout << _name << "say: Miaywoo!" <<std::endl;
}
