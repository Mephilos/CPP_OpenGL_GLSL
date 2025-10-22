//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>
#include <memory>

class MyResource{
public:
    MyResource() {
        std::cout << "Resource acquird!" << std::endl;
    }
    ~MyResource(){
        std::cout << "Resource destroyed!" <<std::endl;
    }
    void sayHello() const {
        std::cout << "Hello from MyResource!" <<std::endl;
    }
};

void sayNull(const std::unique_ptr<MyResource>& ptr) {
    if(ptr == nullptr)
        std::cout << "null: "<< ptr << std::endl;
    else
        std::cout << "Not null: "<< ptr << std::endl;
}

int main(){
    std::shared_ptr<MyResource> ptr1(new MyResource());
    {
        std::shared_ptr<MyResource> ptr2 = ptr1;
        ptr2->sayHello();
        std::cout << "참조 카운트: " << ptr2.use_count() <<std::endl;
        std::cout << ptr1 << std::endl;
        std::cout << ptr2 << std::endl;
    }
    std::cout << "Reference count after ptr2 destruction: " << ptr1.use_count() << std::endl;
    
    return 0;
}





//유니크 포인터
//int main(){
//    std::unique_ptr<MyResource> ptr1(new MyResource());
//    
//    ptr1 -> sayHello();
//    
//    sayNull(ptr1);
//    
//    
//    std::unique_ptr<MyResource> ptr2 = std::move(ptr1);
//    
//    
//    if(!ptr1) {
//        std::cout << "ptr1 is empty after move." <<std::endl;
//    }
//    sayNull(ptr2);
//    sayNull(ptr1);
//    std::cout << ptr1 << std::endl;
//    std::cout << ptr2 << std::endl;
//    
//    return 0;
//}
