#pragma once
#include <string>
#include <iostream>
#include "Ninja.hpp"

using namespace std;
const int SPEED_YOUN = 14;
const int ATTACK_POINT_YOUN = 100;
namespace ariel
{
}
class YoungNinja :public Ninja
{
public:
   YoungNinja(string name, Point point) : Ninja(SPEED_YOUN, point, ATTACK_POINT_YOUN, std::move(name)){};
};