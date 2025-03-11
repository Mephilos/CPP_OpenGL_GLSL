//
//  monster.h
//  C++
//
//  Created by TAEHO SIM on 3/5/25.
//
#ifndef  MONSTER_H
#define  MONSTER_H

#include <string>
#include <iostream>
#include "Position2D.h"
class Monster
{
private:
    std::string _name; //char *data, size_t length
    Position2D _location; //subclass 쪼개야되는건 빨리
    
public:
    //Monster 생성자
    Monster(const std::string name_in, const Position2D pos_in)
        : _name(name_in), _location(pos_in) { }
    
    
    void moveTo(const Position2D& pos_target)
    {
        _location.set(pos_target);
    }
    friend std::ostream& operator << (std::ostream& out, const Monster& monster);
};
std::ostream& operator << (std::ostream& out, const Monster& monster){
    out << monster._name << monster._location;
    return out;
}

#endif //MONSTER_H

