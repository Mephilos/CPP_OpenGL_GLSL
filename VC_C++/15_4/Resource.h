//
//  Resource.h
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#ifndef Resource_h
#define Resource_h
#include <iostream>


class Resource{
//private:
public:
    int* m_data = nullptr;
    size_t m_length = 0;
    
public:
    Resource(){
        std::cout << "Resource default constructed" << std::endl;
    }
    
    Resource(size_t length){
        std::cout << "Resource length constructed" << std::endl;
        
        this->m_data = new int[length];
        this->m_length = length;
    }
    
    Resource(const Resource& res){
        std::cout <<"Resource copy constructed" <<std::endl;
        
        Resource(res.m_length);
        
        for(size_t i = 0; i < m_length; ++i){
            m_data[i] = res.m_data[i];
        }
    }
    ~Resource(){
        std::cout << "Resource destructor" <<std::endl;
        if(m_data != nullptr) delete[] m_data;
    }
    
    Resource& operator = (Resource& res){
        std::cout << "Resource copy assignment" <<std::endl;
        if(this == &res)
            return *this;
        
        if(this->m_data != nullptr) delete [] m_data;
        
        
        m_length = res.m_length;
        m_data = new int[m_length];
        
        for(size_t i = 0 ; i < m_length ; ++i){
            m_data[i] = res.m_data[i];
        }
        
        return *this;
    }

    void print(){
        for(size_t i = 0; i < m_length ; ++i){
            std::cout <<m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    void setAll(const int& v){
        for(size_t i = 0 ; i < m_length ; ++i){
            m_data[i] = v;
        }
    }
};

#endif /* Resource_h */
