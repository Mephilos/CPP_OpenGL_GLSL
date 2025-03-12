//
//  LRvalue.cpp
//  C++
//
//  Created by TAEHO SIM on 3/12/25.
//

#include <iostream>
using namespace std;

class Resource {
public:
    Resource() { cout << "Resource acquired" << endl; }
    ~Resource() { cout << "Resource destroyed" << endl; }
};

void processResource(Resource&& res) {
    // res는 rvalue reference로, 임시 Resource에 바인딩됩니다.
    cout << "Processing resource" << endl;
}

int main() {
    processResource(Resource()); // 임시 객체(Resource())가 rvalue로 전달됨.
    return 0;
}
