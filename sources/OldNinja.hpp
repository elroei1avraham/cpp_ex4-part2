#pragma once
#include <string>
#include <iostream>
#include "Ninja.hpp"

using namespace std;
const int SPEED_OLD = 8;
const int ATTACK_POINT_OLD = 150;
namespace ariel
{
}
class OldNinja :public Ninja
{
public:
    OldNinja(string name, Point point) : Ninja(SPEED_OLD, point, ATTACK_POINT_OLD, std::move(name)){}
};
