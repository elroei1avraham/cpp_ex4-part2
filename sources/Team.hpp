#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

using namespace std;
namespace ariel
{
}
    class Team
    {
    private:
        vector<Character*> army;
        Character* leader;

    public:
        Team(Character *leader);
        Team();
        Team(const Team& otherTeam);
        Team(Team&& otherTeam) = default;
        virtual ~Team();
        void add(Character* Character);
        virtual void attack(Team* otherTeam);
        int stillAlive();
        void print();
        Character* findCloserCharacter(Team* team);
        void sortByCowboyFirst();
        vector<Character*> *getArmy();
        static bool compareCharacters(const Character* characterA, const Character* characterB);
        Team& operator=(const Team& otherTeam) = default;
        Team& operator=(Team&& otherTeam) = default;
    };
