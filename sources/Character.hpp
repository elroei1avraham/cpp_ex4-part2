#pragma once
#include <string>
#include <iostream>
#include "Point.hpp"

using namespace std;
namespace ariel
{
}
    class Character
    {
    private:
        Point point;
        int atPoints;
        string name;
        bool inTeam;

    public:
        Character(Point point,int atPoints, string name);
        Character(const Character &Character);
        Character(Character&& Character) = default; 
        virtual ~Character()=default;
        bool getInTeam();
        void setInTeam();
        bool isAlive();
        double distance(Character *otherCharacter);
        void hit(int num);
        string getName();
        Point& getLocation();
        virtual string print();
        virtual void attack(Character *other){};
        Character& operator=(const Character& Character) = default; 
        Character& operator=(Character&& Character) = default;
        virtual string getRole(){return "Character";};
    };
