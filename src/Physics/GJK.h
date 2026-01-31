#pragma once

#include"Objects.h"
#include"Vec2d.h"

bool GJK(Object* Obj1, Object* obj2);
bool Pass_Origin(ppd VertexPos1, ppd VertexPos2);
bool Contain_Origin(ppd VertexPos1, ppd VertexPos2, ppd VertexPos3);
