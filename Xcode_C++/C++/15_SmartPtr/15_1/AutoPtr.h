//
//  AutoPtr.h
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#ifndef AutoPtr_h
#define AutoPtr_h

#include <iostream>

template<class T>
class AutoPtr{
public:
    T* m_ptr  = nullptr;
    
public:
    AutoPtr(T* ptr = nullptr)
        : m_ptr(ptr)
    {
    }
    ~AutoPtr(){
        if(m_ptr != nullptr) delete m_ptr;
    }
    AutoPtr(AutoPtr& a){
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
    }
    AutoPtr& operator = (AutoPtr& a){
        if(&a == this)
            return *this;
        
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }
    
    
    T& operator*() const { return *m_ptr; }
    T* operator->() const{ return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};


#endif /* AutoPtr_h */
