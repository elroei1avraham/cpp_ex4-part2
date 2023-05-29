#include "Point.hpp"
#include <string>
#include <iostream>
#include <math.h>
using namespace ariel;
using namespace std;

// constructor
Point ::Point(double x_cor, double y_cor)
{
    this->x_cor = x_cor;
    this->y_cor = y_cor;
};

double Point ::distance(Point secondPoint)
{
    double result = sqrt(pow(this->x_cor - secondPoint.x_cor, 2) + pow(this->y_cor - secondPoint.y_cor, 2));
    return result;
};
string Point ::printPoint()
{
    string str = "(" + to_string(this->x_cor) + "," + to_string(this->y_cor) + ")";
    return str;
};
Point Point ::moveTowards(Point sourcePoint, Point destPoint, double distance)
{
    if (distance < 0)
    {
        throw invalid_argument("Distance cannot be small from 0");
    }
    if (distance >= sourcePoint.distance(destPoint))
    {
        return Point(destPoint.getX(), destPoint.getY());
    }
    Point a(sourcePoint.x_cor + distance * (destPoint.x_cor - sourcePoint.x_cor) / sourcePoint.distance(destPoint), sourcePoint.y_cor + distance * (destPoint.y_cor - sourcePoint.y_cor) / sourcePoint.distance(destPoint));
    return a;
};