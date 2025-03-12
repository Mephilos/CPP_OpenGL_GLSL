//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#include "Resource.h"
#include "AutoPtr.h"
#include "Timer.h"

AutoPtr<Resource> generateResource(){
    
    AutoPtr<Resource> res(new Resource(10));
    std::cout<< " ---------------" <<std::endl;
    std::cout<<res.operator->() <<std::endl;
    return res;
}

int main(){
    std::streambuf* orig_buf= std::cout.rdbuf();
    
//    std::cout.rdbuf(NULL);//로그 미출력
    
    Timer timer;
    
    {
        AutoPtr<Resource> main_res;
        std::cout<< " ---------------" <<std::endl;
      
        
        main_res = generateResource();
        std::cout << main_res.operator->()<< std::endl;
    }
    std::cout.rdbuf(orig_buf);
    std::cout << timer.elapsed() <<std::endl;
    
    return 0;
}
