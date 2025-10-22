//
//  shared_Ptr.cpp
//  C++
//
//  Created by TAEHO SIM on 3/13/25.
//

#include <iostream>
#include <memory>

class MyResource{
    
public:
    MyResource(){
        std::cout<< "MyResoure aqcutred" << std::endl;
    }
    
    ~MyResource(){
        std::cout << "MyResource destroyed" << std::endl;
    }
    
    void sayHello() const {
        std::cout << "Hello from MyResource" << std::endl;
    }
};

int main(){
    //shared_ptr rptr1 객체 생성 : rptr 은 new MyResource()를 통해 생성한 객체를 가리킴
    std::shared_ptr<MyResource> rptr1(new MyResource());

    std::shared_ptr<MyResource> shaptr1(new MyResource());
    
    
    std::cout << "rptr1 use_count: " <<rptr1.use_count() <<std::endl;
    
    {
        std::shared_ptr<MyResource> rptr2 = rptr1;
        std::shared_ptr<MyResource> rptr3 = rptr1;
        
        std::shared_ptr<MyResource> shaptr2 = shaptr1;
        std::cout << std::boolalpha;
        std::cout << static_cast<bool>(rptr1) << std::endl;
        std::cout << static_cast<bool>(rptr2) << std::endl;
        std::cout << static_cast<bool>(rptr3) << std::endl;
        
        std::cout << "rptr1 use_count: " << rptr1.use_count() << std::endl;
        std::cout << "rptr2 use_count: " << rptr2.use_count() << std::endl;
        std::cout << "rptr3 use_count: " << rptr3.use_count() << std::endl;
        std::cout << "shaptr1 use_count: " << shaptr1.use_count() << std::endl;
        std::cout << "shaptr2 use_count: " << shaptr2.use_count() << std::endl;
        
        rptr2 -> sayHello();
        rptr3 -> sayHello();
    }
    std::cout << "After block, rptr1 use_count: " <<rptr1.use_count() <<std::endl;
    
    return 0;
}
