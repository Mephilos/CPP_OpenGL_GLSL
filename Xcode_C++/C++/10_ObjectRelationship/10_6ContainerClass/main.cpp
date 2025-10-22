//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/6/25.
//

#include<iostream>
#include<vector>

class IntArray{
private:
    size_t _length = 0;
    int *_ptr_data = nullptr;
    
public:
    //TODO: constructors
    IntArray(const size_t& len_in)
    : _length(len_in)
    {
        _ptr_data = new int[_length];
    }
    IntArray(const std::initializer_list<int> &list)
    : IntArray(list.size())
    {
        int index = 0;
        for(auto init : list){
            _ptr_data[index++] = init;
        }
    }
    //TODO: INITIALIZE()
    void initializer(int initvalue = 0)
    {
        for(size_t index = 0; index<_length; ++index){
            _ptr_data[index]=initvalue;
        }
    }
    //TODO: RESET();
    
    void Reset(const int resetvalue = 0)
    {
        for (size_t index = 0; index<_length; ++index){
            _ptr_data[index] = resetvalue;
        }
    }
    //TODO: RESIZE();
    void Resize(const size_t newSize)
    {
        int* newArray = new int[newSize];
        
        size_t copyLength = (_length < newSize) ? _length : newSize;
        
        for(size_t index = 0; index<copyLength ; ++index){
            newArray[index] = _ptr_data[index];
        }
        for(size_t index = copyLength ; index < newSize; ++index  ){
            newArray[index] = 0;
        }
        
        delete [] _ptr_data;
        _ptr_data = newArray;
        _length = newSize;
    }
    //TODO: INSERTBEFORE(const int& value, const int& ix;)
    
    void Insertbefore(const size_t index, const int& value){
        if(_length<index) return;
        
        //        size_t newSize = _length + 1
        
        int* newArr = new int[_length + 1];
        
        for(int i = 0 ; i < index; ++i){
            newArr[i] = _ptr_data[i];
        }
        newArr[index] = value;
        
        for(size_t i = index + 1; i < _length + 1 ; ++i ){
            newArr[i] = _ptr_data[i-1];
        }
        
        delete [] _ptr_data;
        _ptr_data = newArr;
        _length += 1;
    }
    //TODO: REMOVE(const int & ix);
    void Remove (const size_t index){
        if(index > _length) return;
        
        int* newArr = new int[_length - 1];
        
        for(int i = 0 ; i < index; ++i){
            newArr[i] = _ptr_data[i];
        }
        for(size_t i = index ; i < _length - 1 ; ++i ){
            newArr[i] = _ptr_data[i+1];
        }
        
        delete [] _ptr_data;
        _ptr_data= newArr ;
        _length -= 1;
        
        
    }
    //TODO: PUSH_BACK(const int& value);
    void PushBack(const int& value){
        int* newArray = new int [_length + 1];
        for(int i = 0 ; i < _length ; ++i){
            newArray[i] = _ptr_data[i];
        }
        newArray[_length] = value;
        
        delete [] _ptr_data;
        _ptr_data = newArray;
        _length += 1;
        
    }
    void Print() const {
        for (size_t i = 0; i < _length; ++i) {
            std::cout << _ptr_data[i] << " ";
        }
        std::cout << "\n";
    }
    //TODO: DESTRUCTORS
    ~IntArray()
    {
        delete [] _ptr_data;
    }
};


int main(){
    
    
    IntArray my_arr {1, 3, 5, 7, 9};
    
    my_arr.Print();
    my_arr.Insertbefore(1, 10); //1, 10, 3, 5, 7, 9
    my_arr.Print();
    my_arr.Remove(3);           //1, 10, 3, 7, 9
    my_arr.Print();
    my_arr.PushBack(13);       //1, 10, 3, 7, 9, 13
    my_arr.Print();
    return 0;
}
