//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include "Resource.h"
//RAII: resource acquisition is initialization

void Something(){
    Resource* res = new Resource;
    delete res;
    return;
}

int main(){
    Something();
    return 0;
}
