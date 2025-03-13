#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>


void sequence_containers(){
    // {
    //     std::vector<int> vec;
    //     for(int i = 0; i < 10; ++i)
    //     {
    //         vec.push_back(i);
    //     }
    //     for(auto & e : vec)
    //         std::cout << e << " ";
    // }
    {
        std::deque <int> deq;
        for(int i = 0; i < 10; ++ i)
        {
            deq.push_back(i);
            deq.push_front(i);
        }
        for (auto & e : deq)
            std::cout << e << " ";
        std::cout << std::endl;
    }
}
void associative_containers()
{
    // {
    //     std::set<std::string> str_set;

    //     str_set.insert("Hello");
    //     str_set.insert("World");
    //     str_set.insert("Hello");

    //     std::cout << str_set.size() <<std::endl;

    //     for(auto & e : str_set)
    //         std::cout << e << " ";
    //     std::cout<<std::endl;
    // }

    // {
    //     std::multiset<std::string> str_set;

    //     str_set.insert("hello");
    //     str_set.insert("World");
    //     str_set.insert("Hello");

    //     std::cout << str_set.size() <<std::endl;

    //     for(auto & e : str_set)
    //         std::cout << e << " ";
    //     std::cout<<std::endl;
    // }



    // {
    //     std::map<char, int> map;
    //     map['a'] = 10;
    //     map['b'] = 20;
    //     map['c'] = 50;

    //     std::cout << map['a'] << std::endl;
    //     map['a'] = 100;

    //     std::cout << map['a'] << std::endl;

    //     for(auto& e : map)
    //         std::cout<<e.first << " " <<e.second << " ";
    //     std::cout << std::endl;
    // }
    {
        std::multimap<char,int> map;

        map.insert(std::pair<char,int>('a', 10)); 
        map.insert(std::pair<char,int>('b', 10));
        map.insert(std::pair<char,int>('c', 10));
        map.insert(std::pair<char,int>('a', 100));
        

        std::cout << map.count('a') << std::endl;

        for(auto& e : map)
            std::cout << e.first << " " << e.second << " ";
        std::cout << std::endl;
    }        
}
void container_adapters()
{
    // {
    //     std::cout << "Stack" << std::endl;

    //     std::stack<int> stack;
    //     stack.push(1);
    //     stack.emplace(2);
    //     stack.emplace(3);
    //     std::cout << stack.top() << std::endl;
    //     stack.pop();
    //     std::cout << stack.top() << std::endl;
    // }

    // {
    //     std::cout << "Queue" << std::endl;

    //     std::queue<int> queue;
    //     queue.push(1);
    //     queue.push(2);
    //     queue.push(3);
    //     std::cout << queue.front() << " " <<queue.back() << std::endl;

    //     queue.pop();
    //     std::cout << queue.front() << " " << queue.back() <<std::endl;
    // }


    {
        std::cout << "Priority queue" << std::endl;

        std::priority_queue<int> queue;

        for(const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
            queue.push(n);

        for(int i = 0; i < 10; ++i)
        {
            std::cout << queue.top() << std::endl;
            queue.pop();
        }
    }
}

int main()
{
    sequence_containers();
    associative_containers();
    container_adapters();
}