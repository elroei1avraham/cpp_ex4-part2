#pragma once
#include <string>
#include <iostream>
#include "Character.hpp"

using namespace std;
namespace ariel
{
}
    class Cowboy : public Character
    {
    private:
        int numOfBullets;

    public:
        Cowboy(string name, Point point);
        ~Cowboy() override= default;
        Cowboy(const Cowboy& cowboy) = default;
        Cowboy(Cowboy&& cowboy) = default;
        void shoot(Character* enemy);
        void attack(Character *other) override;
        bool hasboolets();
        void reload();
        string print() override;
        string getRole() override {return "Cowboy";};
        Cowboy& operator=(const Cowboy& cowboy) = default;
        Cowboy& operator=(Cowboy&& cowboy) = default;
    };
