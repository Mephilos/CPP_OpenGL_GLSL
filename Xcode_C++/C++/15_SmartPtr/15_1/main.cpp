//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include "Resource.h"
#include "AutoPtr.h"

//RAII: resource acquisition is initialization

void Something(){
//    Resource* res = new Resource;
    AutoPtr<Resource> res(new Resource);
    return;
}

int main(){
//    Something();
    {
        AutoPtr<Resource> res1(new Resource);
        AutoPtr<Resource> res2;
        
        std::cout << std::boolalpha;
        std::cout <<res1.m_ptr << std::endl;
        std::cout <<res2.m_ptr << std::endl;
        
        res2 = res1;
        
        std::cout <<res1.m_ptr <<std::endl;
        std::cout <<res2.m_ptr <<std::endl;
    }
    
    return 0;
}
