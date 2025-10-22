//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>


class Exception{
public:
    void report(){
        std::cerr << "Exception report" << std::endl;
    }
};

class ArrayException : public Exception{
public:
    void report(){
        std::cerr << "Array exception" <<std::endl;
    }
};


class MyArray{
private:
    int m_data[5];
public:
    int& operator [] (const int& index){
        //if(index < 0 || index >=5) throw -1;
        if(index < 0 || index >=5) throw Exception();
        
        return m_data[index];
    }
};

void Somethting(){
    MyArray my_array;
    
    try{
        my_array[100];
    }
    catch (const int& x){
        std::cerr <<"Exception"<< std::endl;
    }
    
    catch (Exception & e){
        e.report();
    }
}


int main(){
    
    Somethting();
    return 0;
}
