//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/4/25.
//
#include <iostream>
#include <cassert>

class MyString
{
private:
    
public:
    char* _data = nullptr; //동적 할당된 메모리 영역을 가리킴
    size_t _length = 0; //문자열의 길이를 저장, 널 종료 문자 '\0' 까지 포함하여 저장(끝단 확인)
    
public:
    //생성자 주어진 C ㅅ타일 문자열 source를 받아서 문자열의 길이를 계산하고 그 길이에 맞게 동적 메모리를 할당한 후, 문자들의 한 글자 씩 복사합니다.
    MyString(const char* source = "")
    {
        assert(source);// 입력 포인터가 nullptr이 아님을 보장
        
        _length = std::strlen(source) + 1;
        _data = new char[_length];
        
        for(int i =0; i< _length ; ++i)
            _data[i] = source[i];
        
        _data[_length - 1] = '\0';
    }
    MyString(const MyString& source)
    {
        std::cout << "Copy Constructor" << std::endl;
            
        _length = source._length;
        
        if(source._data != nullptr)
        {
            _data = new char[_length];
            
            for (int i = 0; i < _length; ++i)
                _data[i] = source._data[i];
        }
        else
            _data = nullptr;
    }
    
    MyString& operator = (const MyString& source)
    {
        std::cout << "Assignment Operator" <<std::endl;
        //self assignment 시도 무력화
        if ( this == &source)
        {
            return *this;
        }
        delete [] _data; //가지고 있는 데이터 지우기
        
        _length = source._length;
        
        if(source._data != nullptr)
        {
            _data = new char[_length];
            
            for(int i = 0; i < _length; ++i)
            {
                _data[i] = source._data[i];
            }
        }
        else
            _data = nullptr;
        
        return *this;
    }
    ~MyString()
    {
        delete[] _data;
    }
    
    char* getString()
    {
        return _data;
    }
    size_t getLength()
    {
        return _length;
    }
};


int main()
{
    MyString hello("Hello");
    
    MyString copy2;
    
    copy2 = hello;
    
    
    std::cout << (int*)hello._data <<std::endl;
    std::cout << hello.getString() <<std::endl;
    
    {
        MyString copy = hello;
        std::cout <<(int*)copy._data << std::endl;
        std::cout <<copy.getString() << std::endl;
    }
    
    std::cout <<hello.getString() << std::endl;
    return 0;
}
