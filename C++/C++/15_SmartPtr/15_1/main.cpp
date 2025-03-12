//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include "Resource.h"
<<<<<<< HEAD

void Something(){
    Resource* res = new Resource;
    
=======
//RAII: resource acquisition is initialization

void Something(){
    Resource* res = new Resource;
    delete res;
>>>>>>> f726c4f (야간작성코드스마트포인터)
    return;
}

int main(){
<<<<<<< HEAD
    
=======
    Something();
    return 0;
>>>>>>> f726c4f (야간작성코드스마트포인터)
}
