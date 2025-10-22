//
//  Dependency.cpp
//  C++
//
//  Created by TAEHO SIM on 3/6/25.
//

#include "RELATIONSHIPS.h"


GraphicObject::GraphicObject(const std::string& shape_info)
    :_shape(shape_info)
{}

std::string GraphicObject::getShape() const {
    return _shape;
}

void Renderer::render(const GraphicObject& obj) const{
    std::cout <<"Rendering " << obj.getShape() <<std::endl;
}
