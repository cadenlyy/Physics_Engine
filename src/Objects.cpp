#include<iostream>

#include "Objects.h"

Object::Object() {
	Position.Magnitude = { {0,0},{0,0} };
	Velocity.Magnitude = { {0,0},{0,0} };
	Acceleration.Magnitude = { {0,0},{0,0} };
}

Object::Object(const Object& inputObject) {
	Position = inputObject.Position;
	Velocity = inputObject.Velocity;
	Acceleration = inputObject.Acceleration;
	//for (auto i : inputObject.VertexPos.s_get()) VertexPos.s_push_back(i);
	NoVertexPos = inputObject.NoVertexPos;
	//for (auto i : inputObject.IndexPos.s_get()) IndexPos.s_push_back(i);
	for (int i = 0; i < 4; i++) Color[i] = inputObject.Color[i];
}

Ball::Ball(){
	Ball::Position.Magnitude = { {0,0},{0,0} };
	Ball::Velocity.Magnitude = { {0,0},{0,0} };
	Ball::Acceleration.Magnitude = { {0,0},{0,0} };
	Ball::Mass = 0;
	Ball::Radius = 0;
	Ball::Sides = 0;
	Ball::NoVertexPos = (Sides + 1) * 2;
	float color[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < 4; i++) Ball::Color[i] = color[i];
	Ball::VertexPos.s_equ(Ball::VertexOfBall(Radius, Sides));
	Ball::IndexPos.s_equ(Ball::IndexOfBall(Sides));
}

Ball::Ball(ppd Pos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Mass, double Radius, int Sides){
	Ball::Position.Magnitude = Pos;
	Ball::Velocity.Magnitude = Velo;
	Ball::Acceleration.Magnitude = Acc;
	Ball::Mass = Mass;
	Ball::Radius = Radius;
	Ball::Sides = Sides;
	Ball::NoVertexPos = (Sides + 1)*2;
	float color[4] = {Color1, Color2, Color3, Color4};
	for(int i = 0; i < 4; i++) Ball::Color[i] = color[i];
	Ball::VertexPos.s_equ(Ball::VertexOfBall(Radius, Sides));
	Ball::IndexPos.s_equ(Ball::IndexOfBall(Sides));
}

std::vector<ppd> Ball::VertexOfBall(float radius, int Sides) {
	float Radius = radius * 100;
	std::vector <ppd> pos;
	pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100,Position.Magnitude.first.second * 100,0));
	float BaseAng = 2*PI / Sides;
	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first*100 + Radius * sin(ang), Position.Magnitude.first.second * 100 + Radius * cos(ang),0));
		ang -= BaseAng;
	}
	return pos;
}

std::vector<unsigned int> Ball::IndexOfBall(int Count) {
	std::vector <unsigned int> ind;
	for (int i = 1; i <= Count; i++) {
		if (i != Count) {
			ind.push_back(0);
			ind.push_back(i);
			ind.push_back(i + 1);
		}
		else {
			ind.push_back(0);
			ind.push_back(i);
			ind.push_back(1);
		}
	}
	return ind;
}

Simple_pendulum::Simple_pendulum(ppd AnchorPos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Length, double Angv, double Ang, double Radius, int Sides){
	Simple_pendulum::AnchorPos.Magnitude = AnchorPos;
	Simple_pendulum::Position.Magnitude = vec2d::CalculateMagnitude(Simple_pendulum::AnchorPos.Magnitude.first.first + Length * sin(Ang), Simple_pendulum::AnchorPos.Magnitude.first.second - Length * cos(Ang), 0);
	Simple_pendulum::Velocity.Magnitude = Velo;
	Simple_pendulum::Acceleration.Magnitude = Acc;
	Simple_pendulum::Length = Length;
	Simple_pendulum::Angv = Angv;
	Simple_pendulum::Ang = Ang;
	Simple_pendulum::Radius = Radius;
	Simple_pendulum::Sides = Sides;
	Simple_pendulum::NoVertexPos = (Sides + 4)*2;
	float color[4] = { Color1, Color2, Color3, Color4 };
	for (int i = 0; i < 4; i++) Simple_pendulum::Color[i] = color[i];
	Simple_pendulum::VertexPos.s_equ(Simple_pendulum::VertexOfSimplePendulum(Radius, Sides));
	Simple_pendulum::IndexPos.s_equ(Simple_pendulum::IndexOfSimplePendulum(Sides));
}
std::vector<ppd> Simple_pendulum::VertexOfSimplePendulum(float radius, int Sides) {
	float Radius = radius * 100;
	std::vector <ppd> pos;
	pos.push_back(vec2d::CalculateMagnitude(AnchorPos.Magnitude.first.first * 100 + 1.0f * cos(PI / 2 + Ang), AnchorPos.Magnitude.first.second * 100 + 1.0f * sin(PI / 2 + Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(AnchorPos.Magnitude.first.first * 100 + 1.0f * sin(PI / 2 - Ang), AnchorPos.Magnitude.first.second * 100 + 1.0f * cos(PI / 2 - Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 - 1.0f * sin(PI / 2 - Ang), Position.Magnitude.first.second * 100 - 1.0f * cos(PI / 2 - Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 - 1.0f * cos(PI / 2 + Ang), Position.Magnitude.first.second * 100 - 1.0f * sin(PI / 2 + Ang),0));
	float BaseAng = 2 * PI / Sides;
	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 + Radius * sin(ang), Position.Magnitude.first.second * 100 + Radius * cos(ang),0));

		ang -= BaseAng;
	}
	return pos;
}
std::vector<unsigned int> Simple_pendulum::IndexOfSimplePendulum(int Count) {
	std::vector <unsigned int> ind;
	ind.push_back(0); ind.push_back(1); ind.push_back(2); ind.push_back(0); ind.push_back(2); ind.push_back(3);
	for (int i = 5; i <= Count + 3; i++) {
		if (i != Count+3) {
			ind.push_back(4);
			ind.push_back(i);
			ind.push_back(i + 1);
		}
		else {
			ind.push_back(4);
			ind.push_back(i);
			ind.push_back(5);
		}
	}
	return ind;
}

Complex_pendulum::Complex_pendulum(ppd AnchorPos, ppd Velo, ppd Acc, float Color1, float Color2, float Color3, float Color4, double Mass, double Length, double Anga, double Angv, double Ang, double Radius, ppd Velo2, ppd Acc2, double Mass2, double Length2, double Anga2, double Angv2, double Ang2, double Radius2, int Sides) {
	Complex_pendulum::AnchorPos.Magnitude = AnchorPos;
	float color[4] = { Color1, Color2, Color3, Color4 };
	for (int i = 0; i < 4; i++) Complex_pendulum::Color[i] = color[i];

	Complex_pendulum::Position.Magnitude = vec2d::CalculateMagnitude(Complex_pendulum::AnchorPos.Magnitude.first.first + Length * sin(Ang), Complex_pendulum::AnchorPos.Magnitude.first.second - Length * cos(Ang), 0);
	Complex_pendulum::Velocity.Magnitude = Velo;
	Complex_pendulum::Acceleration.Magnitude = Acc;
	Complex_pendulum::Mass = Mass;
	Complex_pendulum::Length = Length;
	Complex_pendulum::Anga = Anga;
	Complex_pendulum::Angv = Angv;
	Complex_pendulum::Ang = Ang;
	Complex_pendulum::Radius = Radius;

	Complex_pendulum::Position2.Magnitude = vec2d::CalculateMagnitude(Complex_pendulum::Position.Magnitude.first.first + Length2 * sin(Ang2), Complex_pendulum::Position.Magnitude.first.second - Length2 * cos(Ang2), 0);
	Complex_pendulum::Velocity2.Magnitude = Velo2;
	Complex_pendulum::Acceleration2.Magnitude = Acc2;
	Complex_pendulum::Mass2 = Mass2;
	Complex_pendulum::Length2 = Length2;
	Complex_pendulum::Anga2 = Anga2;
	Complex_pendulum::Angv2 = Angv2;
	Complex_pendulum::Ang2 = Ang2;
	Complex_pendulum::Radius2 = Radius2;

	Complex_pendulum::Sides = Sides;
	Complex_pendulum::NoVertexPos = (Sides * 8)*2;
	
	Complex_pendulum::VertexPos.s_equ(Complex_pendulum::VertexOfComplexPendulum(Radius, Radius2, Sides));
	Complex_pendulum::IndexPos.s_equ(Complex_pendulum::IndexOfComplexPendulum(Sides));
}

std::vector<ppd> Complex_pendulum::VertexOfComplexPendulum(float radius, float radius2, int Sides) {
	float Radius = radius * 100;
	float Radius2 = radius2 * 100;
	float BaseAng = 2 * PI / Sides;
	std::vector <ppd> pos;

	pos.push_back(vec2d::CalculateMagnitude(AnchorPos.Magnitude.first.first * 100 + 2.0f * cos(PI / 2 + Ang), AnchorPos.Magnitude.first.second * 100 + 2.0f * sin(PI / 2 + Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(AnchorPos.Magnitude.first.first * 100 + 2.0f * sin(PI / 2 - Ang), AnchorPos.Magnitude.first.second * 100 + 2.0f * cos(PI / 2 - Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 - 2.0f * sin(PI / 2 - Ang), Position.Magnitude.first.second * 100 - 2.0f * cos(PI / 2 - Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 - 2.0f * cos(PI / 2 + Ang), Position.Magnitude.first.second * 100 - 2.0f * sin(PI / 2 + Ang),0));

	float ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 + Radius * sin(ang), Position.Magnitude.first.second * 100 + Radius * cos(ang),0));
		ang -= BaseAng;
	}

	pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 + 2.0f * cos(PI / 2 + Ang), Position.Magnitude.first.second * 100 + 2.0f * sin(PI / 2 + Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(Position.Magnitude.first.first * 100 + 2.0f * sin(PI / 2 - Ang), Position.Magnitude.first.second * 100 + 2.0f * cos(PI / 2 - Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(Position2.Magnitude.first.first * 100 - 2.0f * sin(PI / 2 - Ang), Position2.Magnitude.first.second * 100 - 2.0f * cos(PI / 2 - Ang),0));
	pos.push_back(vec2d::CalculateMagnitude(Position2.Magnitude.first.first * 100 - 2.0f * cos(PI / 2 + Ang), Position2.Magnitude.first.second * 100 - 2.0f * sin(PI / 2 + Ang),0));

	ang = 0;
	for (int i = 0; i < Sides; i++) {
		pos.push_back(vec2d::CalculateMagnitude(Position2.Magnitude.first.first * 100 + Radius2 * sin(ang), Position2.Magnitude.first.second * 100 + Radius2 * cos(ang),0));
		ang -= BaseAng;
	}

	return pos;
}

std::vector<unsigned int> Complex_pendulum::IndexOfComplexPendulum(int Count) {
	std::vector <unsigned int> ind;
	ind.push_back(0); ind.push_back(1); ind.push_back(2); ind.push_back(0); ind.push_back(2); ind.push_back(3);
	for (int i = 5; i <= Count + 3; i++) {
		if (i != Count + 3) {
			ind.push_back(4);
			ind.push_back(i);
			ind.push_back(i + 1);
		}
		else {
			ind.push_back(4);
			ind.push_back(i);
			ind.push_back(5);
		}
	}
	ind.push_back(Count+4); ind.push_back(Count + 5); ind.push_back(Count + 6); ind.push_back(Count + 4); ind.push_back(Count + 6); ind.push_back(Count + 7);
	for (int i = Count + 9; i <= Count + 4 + Count + 3; i++) {
		if (i != Count + 4 + Count + 3) {
			ind.push_back(Count + 8);
			ind.push_back(i);
			ind.push_back(i + 1);
		}
		else {
			ind.push_back(Count + 8);
			ind.push_back(i);
			ind.push_back(Count + 9);
		}
	}
	return ind;
}

Multi::Multi(){
}

Multi::Multi(const std::vector <Object*> data){
	for (int i = 0; i < data.size(); i++) {
		Objs.push_back(data[i]);
	}
}


