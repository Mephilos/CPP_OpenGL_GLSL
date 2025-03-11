//
//  main3.cpp
//  C++
//
//  Created by TAEHO SIM on 3/11/25.
//


#include <iostream>


class Node {
public:
    int value;
    Node* child;  // 자식 노드를 가리키는 포인터

    // 생성자: 노드를 만들 때 value를 지정하고, child는 초기에는 nullptr로 설정
    Node(int v) : value(v), child(nullptr) {}
    
    
    int getNode(){
        return value;
    }
};

int main() {
    // 1. 부모 노드를 동적으로 할당하고 값 10으로 초기화
    Node* parent = new Node(10);
    
    std::cout << parent->getNode() <<std::endl;

    // 2. 자식 노드를 동적으로 할당하고 값 20으로 초기화
    Node* child = new Node(20);
    std::cout << parent->child << std::endl;
    // 3. 부모 노드의 member 변수인 child에 자식 노드의 주소(child)를 할당
    parent->child = child;
    std::cout << parent << std::endl;
    std::cout << child << std::endl;
    std::cout << parent->child << std::endl;
    return 0;
}
