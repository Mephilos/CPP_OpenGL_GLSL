//
//  Composition.cpp
//  C++
//
//  Created by TAEHO SIM on 3/6/25.
//

#include "RELATIONSHIPS.h"

Engine::Engine(const std::string& type)
: _type(type)
{
    std::cout <<"Engine created: " <<type <<std::endl;
}
std::string Engine::getType() const{
    return _type;
}


CarComposition::CarComposition(const std::string& model_name, const std::string& engine_type)
: _model(model_name), _engine(engine_type)
{
    std::cout << "Car created: " <<_model << std::endl;
}

void CarComposition::printCar()const{
    std::cout<< "Car Model: " << _model << ", Engine Type: " <<_engine.getType() <<std::endl;
}


