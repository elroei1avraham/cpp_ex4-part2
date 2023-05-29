#pragma once
#include <string>
#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel
{
}
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(int speed, Point point,int atPoints, string name);
        ~Ninja() override = default; 
        Ninja(const Ninja&) = default;
        Ninja(Ninja&&) = default;
        void move(Character* enemy);
        void attack(Character *other) override;
        void slash(Character* otherCharacter);
        string print() override;
        string getRole() override {return "Ninja";};
        Ninja& operator=(const Ninja&) = default;
        Ninja& operator=(Ninja&&) = default;
    };
