//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/6/25.
//

#include "RELATIONSHIPS.h"

int main() {
    Person person("Twilight");
    CarAssoc car("Sedan");
    
    person.setCar(&car);
    person.printInfo();
    
    
    
    
    Student s1("Bob");
    Student s2("Carol");
    Department dept("Computer Science");
    
    dept.addStudent(&s1);
    dept.addStudent(&s2);
    dept.printDepartment();
    
    
    
    CarComposition carComp("Ferrari", "V12");
    carComp.printCar();
    
    GraphicObject circle("Circle");
    Renderer renderer;
    renderer.render(circle);
}
