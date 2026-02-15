#include<iostream>

#include"GJK.h"
#include"Vec2d.h"
#include"Minkowski_Difference.h"
#include"constants.h"
#include"Normal.h"

bool GJK(Object* obj1, Object* obj2){
	Object Obj1(*obj1);
	Object Obj2(*obj2);
	//recalculating obj verticies
	Obj1.VertexPos.s_equ();

	ppd Ang = vec2d::CalculateMagnitude(1, 0, 1);
	ppd VertexPos1, VertexPos2, VertexPos3;

	std::cout << 'a';
	VertexPos1 = Minkowski_Difference(Ang, Obj1, Obj2);
	std::cout << 'b';

	Ang = vec2d::CalculateMagnitude(VertexPos1.second.first, VertexPos1.second.second+PI, 1);
	VertexPos2 = Minkowski_Difference(Ang, Obj1, Obj2);
	if (!Pass_Origin(VertexPos1, VertexPos2)) {
		return false;
	}
	Ang = NormalToOrigin(VertexPos1, VertexPos2);
	VertexPos3 = Minkowski_Difference(Ang, Obj1, Obj2);
	while (VertexPos1 != VertexPos2 && VertexPos1 != VertexPos3 && VertexPos2 != VertexPos3) {
		if (!Pass_Origin(ClosesToOrigin(VertexPos1, VertexPos2), VertexPos3)) {
			return false;
		}
		if (Contain_Origin(VertexPos1, VertexPos2, VertexPos3)) {
			return true;
		}
		if (vec2d::Dot(NormalToOrigin(VertexPos2, VertexPos3), { {0,0},{0,0} }) > vec2d::Dot(NormalToOrigin(VertexPos1, VertexPos3), { {0,0},{0,0} })) {
			VertexPos1 = VertexPos2;
		}
		VertexPos2 = VertexPos3;
		Ang = NormalToOrigin(VertexPos1, VertexPos2);
		VertexPos3 = Minkowski_Difference(Ang, Obj1, Obj2);
	}
	return false;
}

bool Pass_Origin(ppd VertexPos1, ppd VertexPos2) {
	return vec2d::Dot(VertexPos1, VertexPos2) <= 0;
}

bool Contain_Origin(ppd VertexPos1, ppd VertexPos2, ppd VertexPos3) {
	// VertexPos1 is the oldest Vertex and VertexPos3 is the Newest Vertex
	return vec2d::Dot(NormalToOrigin(VertexPos3, VertexPos2), VertexPos3) <= 0 && vec2d::Dot(NormalToOrigin(VertexPos3, VertexPos1), VertexPos3) <= 0;
}

