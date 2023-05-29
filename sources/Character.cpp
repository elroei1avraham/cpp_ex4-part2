#include "Character.hpp"
#include <iostream>
using namespace ariel;
using namespace std;

// constructor
Character ::Character(Point point, int atPoints, string name) : point(point), atPoints(atPoints), name(name)
{
    this->inTeam = false;
};

Character ::Character(const Character &Character): point(Character.point), atPoints(Character.atPoints), name(Character.name)
{
    this->inTeam = Character.inTeam;
}

bool Character:: getInTeam(){
    return this->inTeam;
}

void Character:: setInTeam(){
    this->inTeam=true;
}

bool Character ::isAlive()
{
    if(this->atPoints>0){
        return true;
    }
    return false;
}
double Character ::distance(Character *Character)
{
    return this->point.distance(Character->point);
}
void Character ::hit(int num)
{
    if(num<0){
        throw invalid_argument("the num is must bigger than 0");
    }
    this->atPoints -= num;
}

string Character ::getName()
{
    return this->name;
}

Point& Character ::getLocation()
{
    return this->point;
}
string Character ::print()
{
    string str ="";
    if(this->isAlive()){
        str += "name character: " + this->getName() + " atPoint:" + to_string(this->atPoints) +" the location is: "+ this->getLocation().printPoint(); 
    } else{
        str += "name character: (" + this->getName() + ")";
    }
    return str;
}