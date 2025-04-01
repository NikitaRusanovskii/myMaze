#include "Tile.h"


Tile::Tile(std::shared_ptr<GameObject> obj, Position pos) : obj(obj), pos(pos) {}
Tile::Tile(const Tile& tile) : obj(tile.obj), pos(tile.pos) {}

std::shared_ptr<GameObject> Tile::getObj() {
	return obj;
}

Position Tile::getPosition() {
	return pos;
}

void Tile::setObj(std::shared_ptr<GameObject> newObj){
	obj = newObj;
}

void Tile::setPosition(Position newPos) {
	pos = newPos;
}