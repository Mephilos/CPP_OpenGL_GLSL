//
//  AutoPtr.h
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#ifndef AutoPtr_h
#define AutoPtr_h
#include "Resource.h"


template<class T>
class AutoPtr{
private:
    
public:
    T* m_ptr;
    
public:
    AutoPtr(T* ptr = nullptr) : m_ptr(ptr){
        std::cout<< "오토 포인터 디폴트 생성자" << std::endl;
    }
    ~AutoPtr(){
        std::cout << "오토포인터 소멸자" <<std::endl;
        if(m_ptr != nullptr) delete m_ptr;
    }
    
   AutoPtr(const AutoPtr& a){
       std::cout<< "오토포인터 복사 생성자" << std::endl;
       
       this->m_ptr = new T;
       *m_ptr = *a.m_ptr;
   }
   
   AutoPtr& operator = (const AutoPtr& a){
       std::cout<<"오토 포인터 대입 연산자"<<std::endl;
       
       if(this == &a) return *this;
       
       if(this->m_ptr != nullptr) delete m_ptr;
       
       this->m_ptr = new T;
       *m_ptr = *a.m_ptr;
       
       return *this;
   }
//    AutoPtr(const AutoPtr& a) = delete;
//    AutoPtr& operator = (const AutoPtr& a) = delete;


    AutoPtr(AutoPtr&& a) : m_ptr(a.m_ptr){
        a.m_ptr = nullptr;
        
        std::cout << "오토포인터 이동 생성자" <<std::endl;
    }
    
    AutoPtr& operator = (AutoPtr&& a){
        std::cout << "오토포인터 이동 대입연산자" <<std::endl;
        
        if(this == &a){
            return *this;
        }
        if(!m_ptr) delete m_ptr;
        
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        
        return *this;
    }
    
    T* get() const {
        return m_ptr;
    }
    
    
    T& operator*() const { return *m_ptr; }
    T* operator->() const{ return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
    
};




#endif /* AutoPtr_h */
