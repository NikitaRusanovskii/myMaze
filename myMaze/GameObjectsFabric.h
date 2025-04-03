#pragma once
#include "GameObjects.h"
#include <memory>

class GameObjectFabric {
public:
	~GameObjectFabric() = default;
	virtual std::shared_ptr<GameObject> createObj(Position pos) = 0;
};

class WallFabric : public GameObjectFabric {
public:
	WallFabric() = default;
	std::shared_ptr<GameObject> createObj(Position pos) override;
};

class CoinFabric : public GameObjectFabric {
public:
	CoinFabric() = default;
	std::shared_ptr<GameObject> createObj(Position pos) override;
};

class DoorFabric : public GameObjectFabric {
public:
	DoorFabric() = default;
	std::shared_ptr<GameObject> createObj(Position pos) override;
};

class EmptyFabric : public GameObjectFabric {
public:
	EmptyFabric() = default;
	std::shared_ptr<GameObject> createObj(Position pos) override;
};

class PlayerFabric : public GameObjectFabric {
public:
	PlayerFabric() = default;
	std::shared_ptr<GameObject> createObj(Position pos) override;
};

class MonsterFabric : public GameObjectFabric {
public:
	MonsterFabric() = default;
	std::shared_ptr<GameObject> createObj(Position pos) override;
};