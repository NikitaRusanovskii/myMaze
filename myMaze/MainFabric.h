#pragma once
#include "GameObjectsFabric.h"

class MainFabric {
public:
	MainFabric() = default;
	std::shared_ptr<GameObject> createObj(char objChar, Position pos);
};