//
//  AutoPtr.h
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#ifndef AutoPtr_h
#define AutoPtr_h

class AutoPtr{
public:
    T* m_ptr  = nullptr;
    
public:
    AutoPtr(T* ptr = nullptr)
        : m_ptr(ptr)
    {
        
    }
}


#endif /* AutoPtr_h */
