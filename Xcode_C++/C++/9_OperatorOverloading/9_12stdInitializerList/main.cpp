//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/5/25.
//
#include <iostream>
#include <cassert>
#include <initializer_list>

class IntArray
{
private:
    size_t _length = 0;
    int* _data = nullptr;
    
public:
    IntArray(size_t length)
    : _length(length)
    {
        _data = new int[length];
    }
    IntArray(const std::initializer_list<int> &list)
    : IntArray(list.size())
    {
        int count = 0;
        for( auto& element : list)
        {
            printf("카운트: %d \n",count+1);
            _data[count++] = element;
//            ++count;
        }
        std::cout<<std::endl;
//        아래는 에러 Initializer_list는 [] 기능을 쓰지못함
//        for(size_t count =0; count < list.size(); ++count)
//        {
//            _data[count] = list[count];
//        }
    }
    
    
    friend std::ostream& operator << (std::ostream& out , const IntArray& data);
    IntArray& operator = (const IntArray& data)
    {
        if(this != &data){
            delete [] _data;
            _length = data._length;
            if(data._data)
            {
                _data = new int[_length];
                
                for(size_t i = 0; i <_length ; ++i)
                {
                    _data[i] = data._data[i];
                }
            }
            else
                _data = nullptr;
        }
        return *this;
//        if(this == &data)
//        {
//            return *this;
//        }
//        delete [] _data;
//            
//        _length = data._length;
//            
//        if(data._data!=nullptr)
//            {
//                printf("복사는 되는거임??? \n");
//                _data = new int[_length];
//
//                for(int i = 0; i < _length; ++i)
//                {
//                    printf("복사 %d 카운트 \n", i+1);
//                    _data[i] = data._data[i];
//                }
//            }
//            else
//            {
//                _data = nullptr;
//            }
//        
//        printf("대입연산자 되니??? \n");
//        return *this;
    }
    ~IntArray()
    {
        delete[] this->_data;
    }
};

std::ostream& operator<<(std::ostream& out, const IntArray& data){
    for(size_t i = 0; i <data._length; ++i)
    {
        out << data._data[i] << " ";
    }
    out<<std::endl;
    return out;
}

int main()
{
//    int my_arr1[5] = {1,2,3,4,5};
//    int *my_arr2 = new int[5] {6,7,8,9,0};
//    
//    auto il = {10, 20, 30};
    
    
    IntArray int_array{1, 2,3, 4,5};
    IntArray int_array2 {0,9,8,7,6};
    
    int_array2 = int_array ;
    std::cout << int_array2 <<std::endl;
    return 0;
}
