//
//  Association.cpp
//  C++
//
//  Created by TAEHO SIM on 3/6/25.
//

#include "RELATIONSHIPS.h"

Person::Person(const std:: string& name_in)
    : _name(name_in), _car(nullptr)
{}
void Person::setCar(CarAssoc* car_in) {
    this ->_car = car_in;
}

void Person::printInfo() const{
    std::cout<< "Person: " << _name <<" ";
    
    //차가 있으면 자동차 모델 출력
    if(_car)
        std::cout<< "drives a " << _car->getModel();
    else
        std::cout << "has no car. ";
    std::cout<<std::endl;
}



CarAssoc::CarAssoc(const std::string& model)
    : _model(model)
{}

std::string CarAssoc::getModel() const{
    return _model;
}
