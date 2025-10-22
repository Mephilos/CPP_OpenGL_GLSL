//
//  main.cpp
//  C++
//
//  Created by TAEHO SIM on 3/13/25.
//

#include "Resource.h"
#include <memory>
#include <utility>

auto Something()
{
    auto res1 = std::make_unique<Resource>(5);
    return res1;

    //return std::unique_ptr<Resource>(new Resource(5));

    //return std::make_unique<Resource>(5);
}
void Something2(std::unique_ptr<Resource>& res)
//void Something2(Resource* res)
{
    res->setAll(10);
    res->print();

//    return res;
}

int main()
{
    //{
    //    std::unique_ptr<int> upi(new int);

    //    //std::unique_ptr<Resource> res1(new Resource(5));
    //    auto res1 = std::make_unique<Resource>(5);
    //    //auto res1 = Something();

    //    res1->setAll(5);
    //    res1->print();

    //    std::unique_ptr<Resource> res2;

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl; // res1은 유효한 객체를 가리킵니다.
    //    std::cout << static_cast<bool>(res2) << std::endl; // res2는 아직 초기화되지 않았으므로 false입니다.

    //    res2 = std::move(res1); // res1의 소유권을 res2로 이전합니다.

    //    std::cout << std::boolalpha;
    //    std::cout << static_cast<bool>(res1) << std::endl; // res1은 더 이상 유효한 객체를 가리키지 않으므로 false입니다.
    //    std::cout << static_cast<bool>(res2) << std::endl; // res2는 이제 유효한 객체를 가리키므로 true입니다.


    //    if (res1 != nullptr) res1->print();
    //    std::cout << "----------------------" << std::endl;
    //    if (res2 != nullptr) res2->print(); //이쪽이 출력
    //}




    {
        auto res1 = std::make_unique<Resource>(5);

        res1->setAll(1);
        res1->print();
        std::cout << std::boolalpha;
        std::cout << static_cast<bool>(res1) << std::endl;

        Something2(res1); //Something 함수에서 중괄호가 나가지므로 거기서 소멸함.
        //Something2(res1.get());
        std::cout << std::boolalpha;
        std::cout << static_cast<bool>(res1) << std::endl;
    }



    //그냥 하면 안되는 코드. 유니크 포인터에 썼던 객체를 넣음. 그리고 수동으로 삭제 시도. 문법에 맞지 않음.
    /*{
        Resource* res = new Resource;
        std::unique_ptr<Resource> res1(res);
        std::unique_ptr<Resource> res2(res);

        delete
    }*/
    return 0;

}
