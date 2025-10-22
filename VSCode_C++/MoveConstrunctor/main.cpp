#include <iostream>
#include <cstring>

//texture는 동적 메모리로 텍스처 데이터를 저장
//실제 게임에서는 픽셀 데이터나 이미지 버퍼를 관리할 수 있음.

class Texture
{
private:
    char* _data; // 텍스처 데이터를 저장하는 동적 배열
    size_t _size;    // 텍스처 데이터의 크기
public:
    //생성자
    Texture(const char* src){
        if(src){
            _size = strlen(src) + 1; // 널 종료 문자 포함
            _data = new char[_size];
            std::memcpy(_data, src, _size);
        }
        else{
            _size = 0;
            _data = nullptr;
        }
        std::cout<< "Texture Constructor: " << _data<< std::endl;
    }
    ~Texture(){
        delete[] _data;
        std::cout<< "Texture Destructor: " << std::endl;
    }
//  //복사 생성자
    Texture(const Texture& other) : _size(other._size) {
        if(other._data){
            _data = new char[_size];
            std::memcpy(_data, other._data, _size);
        }
        else{
            _data = nullptr;
        }
        std::cout<< "Texture Copy Constructor: " << _data<< std::endl;
    }
    Texture& operator=(const Texture& other){
        if(this != &other){
            delete[] _data;
            _size = other._size;
            if(other._data){
                _data = new char[_size];
                std::memcpy(_data, other._data, _size);
            }
            else{
                _data = nullptr;
            }
            std::cout << "Texture Copy Assignment Operator: " << _data << std::endl;
        }
        return *this;
    }

    Texture(Texture&& other) noexcept : _data(other._data), _size(other._size){
        other._data = nullptr;
        other._size = 0;
        std::cout << "Texture Move Constructor: " << _data << std::endl;
    }
    Texture& operator=(Texture&& other) noexcept{
        if(this != &other){
            delete[] _data;
            _data = other._data;
            _size = other._size;
            other._data = nullptr;
            other._size = 0;
            std::cout << "Texture Move Assignment Operator: " << _data << std::endl;
        }
        return *this;
    }

    void Print() {
        std::cout << "Texture data: " << (_data ? _data : "null") << std::endl;
    }
};


int main() {
    // 텍스처 로딩 (실무에서는 파일에서 이미지 데이터를 읽어옵니다)
    Texture tex1("Level1_Texture");
    tex1.Print();
    
    // 복사 생성자 사용: 텍스처를 복사할 경우, 복사 생성자가 호출되어 deep copy 실행
    Texture tex2 = tex1; 
    tex2.Print();
    
    // 이동 생성자 사용: 임시 객체를 이용해 텍스처를 이동시킴
    Texture tex3 = std::move(tex1);
    tex3.Print();
    tex1.Print();  // tex1은 이동 후 빈 상태(null 출력)
    
    // 이동 대입 연산자 사용: 이미 존재하는 객체에 대해 텍스처 이동
    Texture tex4("Temporary_Texture");
    tex4.Print();
    tex4 = std::move(tex2);
    tex4.Print();
    tex2.Print();  // tex2는 이동 후 빈 상태
       
    return 0;
}

