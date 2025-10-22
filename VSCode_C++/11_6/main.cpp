#include <iostream>
#include <algorithm>


template <typename T, int size>
class StaticArray
{
private:
    T m_array[size];
public:
    T* getArray() { return m_array; }
    T& operator[](int index) { return m_array[index]; }
};

template <typename T, int size>
void print(StaticArray<T, size>& array)
{
    for (int count = 0; count < size; ++count)
        std::cout << array[count] << ' ';
    std::cout << std::endl;
}
int main()
{
    StaticArray<char, 14> char14;
    char14[0] = 'H';
    char14[1] = 'e';
    char14[2] = 'l';
    char14[3] = 'l';
    char14[4] = 'o';
    char14[5] = ',';
    char14[6] = ' ';
    char14[7] = 'W';
    char14[8] = 'o';
    char14[9] = 'r';
    char14[10] = 'l';
    char14[11] = 'd';
    char14[12] = '!';
    char14[13] = '\0';
    
    print(char14);
 
}