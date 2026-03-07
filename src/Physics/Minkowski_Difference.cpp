#include"Minkowski_Difference.h"
#include"Vec2d.h"
#include"Support.h"
#include"constants.h"
#include<iostream>

ppd Minkowski_Difference(ppd Ang, Object* Obj1, Object* Obj2) {
	//std::cout << 'c';
	std::cout << Support(Ang, Obj1).first.first << ' ' << Support(Ang, Obj1).first.second << '\n';
	std::cout << Support(vec2d::CalculateMagnitude(Ang.second.first, Ang.second.second + PI, 1), Obj2).first.first << ' ' << Support(vec2d::CalculateMagnitude(Ang.second.first, Ang.second.second + PI, 1), Obj2).first.second << '\n';
	std::cout << vec2d::Sub(Support(Ang, Obj1), Support(vec2d::CalculateMagnitude(Ang.second.first, Ang.second.second + PI, 1), Obj2)).first.first << ' ' << vec2d::Sub(Support(Ang, Obj1), Support(vec2d::CalculateMagnitude(Ang.second.first, Ang.second.second + PI, 1), Obj2)).first.second << '\n';
	std::cout << '\n';
	return vec2d::Sub(Support(Ang, Obj1), Support(vec2d::CalculateMagnitude(Ang.second.first,Ang.second.second+PI,1),Obj2));
}