//
//  Aggregation.cpp
//  C++
//
//  Created by TAEHO SIM on 3/6/25.
//

#include "RELATIONSHIPS.h"

Student::Student(const std::string& name)
    : _name(name)
{}

std::string Student::getName() const{
    return _name;
}

Department::Department(const std::string& name)
    : _deptName(name)
{}
void Department::addStudent(Student *s){
    _students.push_back(s);
}

void Department::printDepartment() const {
    std::cout << "Department: " << _deptName <<std::endl;
    std::cout << "Student: ";
    
    for(auto stu : _students){
        std::cout << stu->getName() << " ";
    }
    std::cout<< std::endl;
}
