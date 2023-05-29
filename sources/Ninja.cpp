#include "Ninja.hpp"
#include <string>
#include <iostream>
using namespace ariel;
using namespace std;

// constructor
Ninja ::Ninja(int speed, Point point, int atPoints, string name) : Character(point, atPoints, name)
{
    this->speed = speed;
};

void Ninja ::move(Character *enemy)
{
    this->getLocation() = this->getLocation().moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
}

void Ninja ::slash(Character *otherCharacter)
{
    if(this == otherCharacter){
        throw runtime_error("the target is my i am not self harm");
    }
    if(!(otherCharacter->isAlive())){
        throw runtime_error("the target is dead");
    }
    if(!(this->isAlive())){
        throw runtime_error("the Ninja is dead");
    }
    else 
    {
        if (this->distance(otherCharacter) < 1)
        {
            otherCharacter->hit(40);
        }
    }
}

void Ninja ::attack(Character *other){
    slash(other);
}

string Ninja ::print()
{
    string str = (*this).Character::print();
    return "N " + str;
}