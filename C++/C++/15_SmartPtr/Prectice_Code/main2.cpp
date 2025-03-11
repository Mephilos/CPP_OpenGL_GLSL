//
//  main2.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//

#include <iostream>
#include <memory>

class Node{
public:
    std::weak_ptr<Node> parent;
    std::shared_ptr<Node> child;
    ~Node() { std::cout << "Node destroyed" << std::endl; }
};

int main(){
    {
        std::shared_ptr<Node> parent = std::make_shared<Node>();
        std::shared_ptr<Node> child = std::make_shared<Node>();
        
        parent->child =child;
        child ->parent = parent;
        
        std::cout << parent.use_count() << std::endl;
        std::cout << child.use_count()<< std::endl;
        
        parent->child = child;
    }
}
