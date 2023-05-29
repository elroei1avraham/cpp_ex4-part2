#include "Cowboy.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

// constructor
Cowboy ::Cowboy(string name, Point point):Character(point,110,name)
{
    this->numOfBullets = 6;
};
void Cowboy :: shoot(Character* enemy)
{
    if(this == enemy){
        throw runtime_error("the target is me, I don't shoot myself");
    }
    if(!(enemy->isAlive())){
        throw runtime_error("the target is dead");
    }
    if(!(this->isAlive())){
        throw runtime_error("the Cowboy is dead");
    }
    if(this->hasboolets()){
        enemy->hit(10);
        this->numOfBullets--;
    }
    else{
        this->reload();
    }
}

void Cowboy ::attack(Character *other) {
    shoot(other);
}

bool Cowboy ::hasboolets()
{
    if(this->numOfBullets>0){
        return true;
    }
   return false; 
}
void Cowboy :: reload()
{
    if(!this->isAlive()){
        throw runtime_error("the Cowboy is dead");
    }
    this->numOfBullets = 6;
}
string Cowboy ::print()
{
    string str = (*this).Character::print();
    return "C " + str;
}