#pragma once
#include "__fwd.h"
#include "GameObjects.h"
#include <memory>

class MainFabric {
public:
	MainFabric() = default;
	std::shared_ptr<GameObject> createObj(char texture, int x, int y);
};

class EmptyFabric {
public:
	EmptyFabric() = default;
	std::shared_ptr<GameObject> createObj(char texture);
};