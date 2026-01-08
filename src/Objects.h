#pragma once

#include <vector>
#include <string>

#include "Physics/Vec2d.h"
#include "Physics/constants.h"
#include "s_vector.h"

class Object {
public:
    Object();
    Object(Object& inputObject);
    vec2d Position;
    vec2d Velocity;
    vec2d Acceleration;
    s_vector <ppd> VertexPos;
    int NoVertexPos;
    s_vector <unsigned int> IndexPos;
    float Color[4];
};

class Ball: public Object{
public:
    Ball();
    Ball(ppd Pos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Mass, double Radius, int Sides);
    double Mass;
    double Radius;
    int Sides;
    std::vector<ppd> VertexOfBall(float radius, int Sides);
private:
    std::vector<unsigned int> IndexOfBall(int Count);
};

class Simple_pendulum: public Object{
public:
    Simple_pendulum(ppd AnchorPos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Length, double Angv, double Ang, double Radius, int Sides);
    vec2d AnchorPos;
    double Length;
    double Angv;
    double Ang;
    double Radius;
    int Sides;
    std::vector<ppd> VertexOfSimplePendulum(float radius, int Sides);
private:
    std::vector<unsigned int> IndexOfSimplePendulum(int Count);
};
class Complex_pendulum: public Object{
public:
    Complex_pendulum(ppd AnchorPos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Mass, double Length, double Anga, double Angv, double Ang, double Radius, ppd Velo2, ppd Acc2, double Mass2, double Length2, double Anga2, double Angv2, double Ang2, double Radius2, int Sides);

    vec2d AnchorPos;

    double Mass;
    double Length;
    double Anga;
    double Angv;
    double Ang;
    double Radius;
    
    vec2d Position2;
    vec2d Velocity2;
    vec2d Acceleration2;
    double Mass2;
    double Length2;
    double Anga2;
    double Angv2;
    double Ang2;
    double Radius2;

    int Sides;
    std::vector<ppd> VertexOfComplexPendulum(float radius, float radius2, int Sides);
private:
    std::vector<unsigned int> IndexOfComplexPendulum(int Count);
};

class constraint {
private:
    std::vector<Object> Objs;

public:
    //constructors
    constraint();

    constraint(const Object* data);

    //destructor
    ~constraint();
};