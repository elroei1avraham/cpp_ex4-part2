#pragma once
#include <string>
#include <iostream>

using namespace std;
namespace ariel
{
}
    class Point
    {
    private:
        double x_cor;
        double y_cor;

    public:
        Point(double x_cor=0, double y_cor=0);
        double distance(Point secondPoint);
        string printPoint();
        static Point moveTowards(Point sourcePoint, Point destPoint, double distance);
        double getX()const{return x_cor;};
        double getY()const{return y_cor;};
    };
