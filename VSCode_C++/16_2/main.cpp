#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>


int main()
{
    // std::list<int> container;
    // for (int i = 0; i < 10; ++i)
    //     container.push_back(i);

    // std::vector<int>::const_iterator itr;

    // itr = container.begin();
    // while(itr != container.end())
    // {
    //     std::cout << *itr << " ";

    //     ++itr;
    // }
    // std::cout << std::endl;

    // for (auto & e : container)
    //     std::cout << e << " ";
    // std::cout << std::endl;

    // for(auto itr = container.begin(); itr != container.end(); ++itr){
    //     std::cout << *itr <<std::endl;
    // }

    std::set<int> container;

    for(int i = 0 ; i < 10 ; i++)
    {
        container.insert(i);
    }

    for(auto itr = container.begin(); itr != container.end(); ++itr)
        std::cout << * itr << " ";
        
    std::cout<< std::endl;

    return 0;
}