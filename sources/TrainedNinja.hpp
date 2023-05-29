#pragma once
#include <string>
#include <iostream>
#include "Ninja.hpp"

using namespace std;
const int SPEED_TRA = 12;
const int ATTACK_POINT_TRA = 120;
namespace ariel
{
}
class TrainedNinja :public Ninja
{
public:
    TrainedNinja(string name, Point point) : Ninja(SPEED_TRA, point, ATTACK_POINT_TRA, std::move(name)){};
};