//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>


void last(){
    std::cout << "last" << std::endl;
    std::cout << "Throws exception" << std::endl;

    throw -1;
    
    std::cout << "End last" << std::endl;
}


void third(){
    std:: cout << "Third" << std::endl;

    last();

    std::cout<<"End third" <<std::endl;
}

void second(){
    std::cout <<  "second" << std::endl;

    try {
        third();
    }
    catch (double){
        std::cerr << "Second caught double exception" << std::endl;
    }
    std::cout <<"End second" << std::endl;
}

void first(){
    std::cout<< "first" <<std::endl;

    try{
        second();
    }
    catch(int){
        std::cerr<<"first caught in exception" << std::endl;
    }

    std::cout << "End first" << std::endl;
}


int main()
{
    std::cout << "Start" <<std::endl;
    
    try{
        first();
    }
    catch (int) {
        std::cerr << "main caught int exception" << std::endl;
    }
    
    return 0;
}

