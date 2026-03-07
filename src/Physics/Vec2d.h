#pragma once

#include<vector>
#include "Vec2d.h"

typedef std::pair<double, double> pd;
typedef std::pair<pd,pd> ppd; //first pair is cartesian coordinates {x,y}, second pair is polar coordinates {r,theta}

class vec2d{
public:
    ppd Magnitude;
    static ppd CalculateMagnitude(double x, double y, bool c);
    static ppd Add(ppd x, ppd y);
    static ppd Sub(ppd x, ppd y);
    static ppd Multi(ppd x, ppd y);
    static ppd Divide(ppd x, ppd y);
    static ppd Sum(std::vector <ppd> v);
    static double AngleAdd(double x, double y);
    static double Dot(ppd x, ppd y);
    static ppd Cross(ppd x, ppd y);
};