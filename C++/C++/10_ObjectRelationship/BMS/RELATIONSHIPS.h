//
//  RELATIONSHIPS.h
//  C++
//
//  Created by TAEHO SIM on 3/6/25.
//

#ifndef RELATIONSHIPS_h
#define RELATIONSHIPS_h

#include <iostream>
#include <string>
#include <vector>

//Association(연관)
//두 객체가 서로 정보를 주고 받거나 알고 있는 관계;
//사람과 차의 관계
class CarAssoc;

class Person
{
private:
    
    std::string _name;
    CarAssoc* _car; 
public:
    Person(const std::string& name);
    void setCar(CarAssoc* car);
    void printInfo() const;
};

class CarAssoc{
private:
    std::string _model;
public:
    CarAssoc(const std::string& model);
    std::string getModel() const;
};


//집합 관계 Aggregation
//부분(part)들이 전체(whole)에 속하지만 생명주기는 독립적인관계
//학부와 학생
//Department는 여러Student 객체의 포인터를 보관하지만,
//Student 객체들은 Department 외부에서도 독립적으로 존재할수 있습니다.


//학생은 이름을 맴버 변수로 가짐.
class Student{
private:
    std::string _name;
public:
    Student(const std::string& name);
    std::string getName() const;
};

class Department{
private:
    std::string _deptName;
    std::vector<Student*> _students;
public:
    Department(const std::string& name);
    void addStudent(Student* s);
    void printDepartment() const;
};

//Composition(합성)
//전체(Whole)이 부분(part)를 강하게 소유하며, 전체의 생명주기에 부분이 종속되는 관계
//예제: car(자동차)와 Engine(엔진)
//-Car는 Engine을 멤버 변수로 직접 포함하고, Car가 소멸되면 Engine도 같이 소멸됩니다.

class Engine{
private:
    std::string _type;
public:
    Engine(const std::string& type);
    std::string getType() const;
};


class CarComposition{
private:
    std::string _model;
    Engine _engine;
public:
    CarComposition(const std::string& model, const std::string& engineType);
    void printCar()const;
};

//Dependency(의존)
//한 객체의 기능이 다른 객체의 존재에 "일시적으로" 의존하는 관계.
//예제: Renderer(렌더러)와 GraphicObject(그래픽 객체)
//- Renderer의 render()함수는 GraphicObject의 정보를 사용하여 그리기를 수행합니다.
// 서로 의존적인관계???
class GraphicObject{
private:
    std::string _shape;
public:
    GraphicObject(const std::string& shape);
    std::string getShape() const; //getter, 접근자 함수
};
class Renderer{
public:
    void render(const GraphicObject& obj) const;
};


#endif /* RELATIONSHIPS_h */
