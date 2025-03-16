#include <iostream>
#include <string>

class CustomString {
private:
    std::string data;
public:
    CustomString() : data("") {}

    explicit CustomString(const std::string& str) : data(str) {}

    CustomString(CustomString&& other) noexcept {
        std::cout << "Move Constructor Called" << std::endl;
        data = std::move(other.data);
    }

    CustomString& operator = (CustomString&& other) noexcept {
        std::cout << "Move Assignment Operator Called" <<std::endl;
        data = std::move(other.data);
        return* this;
    }

    void print() const {
        std::cout<< "Data: " << data << std::endl;
    }
};
CustomString createTemporaryString(){
    return CustomString("Temporary String");
}

int main() {
    CustomString str1;

    str1 = createTemporaryString();

    str1.print();
    
    return 0;
}
