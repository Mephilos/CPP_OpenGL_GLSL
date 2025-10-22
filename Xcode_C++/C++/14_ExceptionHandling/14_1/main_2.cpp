//
//  main_2.cpp
//  C++
//
//  Created by TAEHO SIM on 3/10/25.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    //try, catch, throw 깔끔 하긴한데 퍼포먼스가 안좋아질수 있으므로 퍼포먼스가 필요한 상황에서는 사용응 지양하도록 한다.
    double x;
    std::cin >>x;
    
    try
    {
        if (x < 0.0) throw std::string("Negative input");
        
        std::cout<< std::sqrt(x) << std::endl;
    }
    catch (std::string error_message)
    {
        std::cout<< error_message << std::endl;
    }
    //catch는 여러개 쓸수도 있음. int double, char * message , string ("") 같은 자료형은 일치 시켜야함 안그럼 못받음

    
    return 0;
}
