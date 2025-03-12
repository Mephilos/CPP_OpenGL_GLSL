#pragma once

#include <iostream>

class Resource{
private:
public:
    int m_data[100];
    
public:
    Resource(){
        std::cout << "Resource constructed" << std::endl;
    }
    
    ~Resource(){
        std::cout << "Resource constructed" << std::endl;
    }
};

