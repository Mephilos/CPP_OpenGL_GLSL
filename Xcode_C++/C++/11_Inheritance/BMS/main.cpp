//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/7/25.
//
#include "InheritanceExample.h"


int main(){
    
    Animal* animals[2];
    animals[0] = new Dog("Buddy");
    animals[1] = new Cat("Kitty");
    
    for(int i =0; i < 2 ; ++i){
        animals[i]->speak();
    }
    
    for (int i = 0 ; i < 2 ; ++i){
        delete animals[i];
    }
    
    
    Flamingo flamingo;
    flamingo.fly();
    flamingo.showColor();
    
    
    return 0;
}
