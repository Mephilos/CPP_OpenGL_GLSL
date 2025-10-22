//
//  bms.cpp
//  C++
//
//  Created by TAEHO SIM on 3/4/25.
//

#include <iostream>
#include <cstring>

class Sprite{
private:
    char* texture;
    
public:
    Sprite(const char* data = nullptr){
        if(data){
            texture = new char[strlen(data) + 1];
            stpcpy(texture, data);
        }
        else{
            texture = nullptr;
        }
    }
    
    Sprite(const Sprite& other){
        if(other.texture){
            texture = new char[strlen(other.texture) + 1];
            strcpy(texture, other.texture);
        }
        else{
            texture = nullptr;
        }
    }
    
    Sprite& operator=(const Sprite& other){
        if(this != &other){
            delete[] texture;
            if(other.texture){
                texture = new char[strlen(other.texture) + 1];
                strcpy(texture, other.texture);
            }
            else{
                texture = nullptr;
            }
        }
        return *this;
    }
    
};
