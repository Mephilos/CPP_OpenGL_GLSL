//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/10/25.
//
#include <iostream>
#include <cstring>

template<typename T>

class Storage
{
private:
    T m_value;
    
public:
    Storage(T value)
        : m_value(value) {}
    
    T getValue() const
    {
        return m_value;
    }
    
    void print() const
    {
        std::cout << m_value << std::endl;
    }
};

//Storage<char*>의 전체특수화(Full specialization)
template<>
class Storage<char*>
{
private:
    char* m_value;
public:
    Storage(char* value){
        m_value = new char[strlen(value) + 1];
        strcpy(m_value,value);
    }
    ~Storage(){
        delete [] m_value;
    }
    char* getValue() const {
        return m_value;
    }
    
    void print() const { std:: cout << m_value << std::endl;}
};
int main()
{
    Storage<int> intStorage(42);
    intStorage.print();
    
    Storage<double> doubleStorage(3.14);
    doubleStorage.print();
    
    Storage<std::string> nonStringStorage("Hello");
    nonStringStorage.print();
    
    char text[] = "Hello, World!";
    
    Storage<char*> stringStorage(text);
    stringStorage.print();
    
    return 0;
}
