#include "Team.hpp"
#include <iostream>
#include <vector>
#include <float.h>
#include <typeinfo>
#include <algorithm>
using namespace ariel;
using namespace std;

Team ::Team(Character *leader)
{
    if (leader->getInTeam())
    {
        throw runtime_error("the character in the team");
    }
    this->leader = leader;
    army.push_back(leader);
    leader->setInTeam();
}

Team ::Team()
{
}
Team ::Team(const Team& otherTeam)
{
    this->leader = otherTeam.leader;
}

Team::~Team() {
  for (Character *member : this->army)
    delete member;
  this->army.clear();
}

void Team ::add(Character *Character)
{
    if (army.size() == 10)
    {
        throw runtime_error("there are maximum 10 members that are not already in other teams");
    }
    if (Character->getInTeam())
    {
        throw runtime_error("the character in the team");
    }

    army.push_back(Character);
    this->sortByCowboyFirst();
    Character->setInTeam();
}
void Team ::attack(Team *otherTeam)
{
    if (otherTeam == nullptr)
    {
        throw invalid_argument("otherTeam is nullptr");
    }
    if (this->stillAlive() <= 0)
    {
        throw runtime_error("all team are dead");
    }
    if (otherTeam->stillAlive() <= 0)
    {
        throw runtime_error("enemy team is dead");
    }
    if (!(this->leader->isAlive()))
    {
        this->leader = findCloserCharacter(this);
    }
    if (otherTeam->stillAlive() > 0)
    {
        Character* target = findCloserCharacter(otherTeam);
        for (Character *attacker : army)
        {
            if (attacker->isAlive())
            {
                if (!target->isAlive())
                {
                    if (otherTeam->stillAlive() == 0)
                    {
                        return;
                    }
                    target = findCloserCharacter(otherTeam);
                }
                if (attacker->getRole() == "Ninja" && attacker->distance(target) > 1)
                {
                    ((Ninja *)attacker)->move(target);
                }
                else
                {
                    attacker->attack(target);
                }
            }
        }
    }
}

int Team ::stillAlive()
{
    int countAlive = 0;
    for (Character *member : this->army)
    {
        if (member->isAlive())
        {
            countAlive++;
        }
    }
    return countAlive;
}

void Team ::print()
{
    string str = "";
    for (Character *member : this->army)
    {
        str += member->print();
        str += "\n";
    }
    cout << str << endl;
}

Character *Team::findCloserCharacter(Team *team)
{
    double shortestMember = DBL_MAX;
    Character *target = nullptr;
    for (Character *member : team->army)
    {
        if (member->isAlive() && this->leader->distance(member) < shortestMember)
        {
            shortestMember = this->leader->distance(member);
            target = member;
        }
    }
    return target;
}

void Team::sortByCowboyFirst()
{
    // Sort the vector using the custom comparison function
    sort(army.begin(), army.end(), compareCharacters);
}
vector<Character*> *Team::getArmy()
{
    return &army;
}
// Custom comparison function for sorting pointers to Character objects
bool Team::compareCharacters(const Character* characterA, const Character* characterB)
{
    if ((typeid(characterA) != typeid(Cowboy)) && (typeid(characterB) == typeid(Cowboy)))
    {
        return true;
    }
    return false;
}