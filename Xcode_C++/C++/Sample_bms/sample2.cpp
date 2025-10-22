//
//  sample2.cpp
//  C++
//
//  Created by TAEHO SIM on 3/13/25.
//

#include <iostream>
#include <istream>
class Point{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y){}
    
    void ShowPosition() const {
        std::cout << '[' << xpos << ", " << ypos << ']' <<std::endl;
    }
    friend std::ostream& operator << (std::ostream& os, const Point& pos){
        
        os<<'['<<pos.xpos <<", " << pos.ypos <<']' <<std::endl;
        return os;
    }
    friend std::istream& operator >> (std::istream& in, Point& pos){
        in >> pos.xpos >> pos.ypos;
        return in;
    }
    
};

int main()
{
    Point pos1;
    std::cout << "좌표 순으로 입력: ";
    std::cin >> pos1;
    std::cout<<pos1 << std::endl;
    
    
    Point pos2;
    std::cout << "좌표 순으로 입력: ";
    std::cin >> pos2;
    std::cout<< pos2 << std::endl;
    return 0;
}
