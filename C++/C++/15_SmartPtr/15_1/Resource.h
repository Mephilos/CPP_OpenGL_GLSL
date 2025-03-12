//
//  Resource.h
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//
#ifndef Resource_h
#define Resource_h

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

#endif /* Resource_h */
