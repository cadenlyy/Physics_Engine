#include <vector>
#include <algorithm>
#include <iostream>

#include "Vec2d.h"
#include "Objects.h"
#include "Support.h"

ppd Support(ppd Ang, Object Obj) {
	std::cout << 'd';
	std::vector<std::pair<double, ppd>> SupportStore;
	for (ppd i : Obj.VertexPos.s_get()) {
		std::cout << i.first.first;
		SupportStore.push_back(make_pair(vec2d::Dot(Ang, i),i));
	}
	std::pair<double, ppd> Supp = *std::max_element(SupportStore.begin(),SupportStore.end());
	return Supp.second;
}