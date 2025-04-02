#pragma once
#include "GameObjects.h"
#include <memory>


class Tile {
private:
	std::shared_ptr<GameObject> obj;
	Position pos;
public:
	Tile(std::shared_ptr<GameObject> obj = nullptr, Position pos = Position());
	Tile(const Tile& tile);
	~Tile() = default;

	std::shared_ptr<GameObject> getObj();
	Position getPosition();

	void setObj(std::shared_ptr<GameObject> newObj);
	void setPosition(Position newPos);
};

std::shared_ptr<Tile> operator+=(std::shared_ptr<Tile> a, std::shared_ptr<Tile> b);