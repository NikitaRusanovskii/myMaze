#include "Tile.h"
#include "GameObjects.h"
#include "MazeDrawer.h"
#include "Fabric.h"
#include "MyExceptions.h"
#include <memory>
#include <vector>


using namespace std;

vector<shared_ptr<Observer>>& Observable::getSubs() {
	return subscribers;
}

Tile::Tile(shared_ptr<GameObject> object) : Observable(), object(object) {}
shared_ptr<GameObject> Tile::getObject() {
	return object;
}
void Tile::setObject(shared_ptr<GameObject> _object) {
	object = _object;
}

std::shared_ptr<GameObject>& Tile::getObjectRef() {
	return object;
}

shared_ptr<Tile> operator+=(shared_ptr<Tile> curTile, shared_ptr<Tile> otherTile) {
	if (curTile->getObject()->getType() == "Wall") throw WallException();
	else if (curTile->getObject()->getType() == "Coin") throw CoinException();
	else if (curTile->getObject()->getType() == "Door") throw DoorException();
	else {
		swap(curTile->getObjectRef(), otherTile->getObjectRef());
		curTile->notify();
	}
	return curTile;
}
shared_ptr<Tile> operator-=(shared_ptr<Tile> curTile, shared_ptr<Tile> otherTile) {
	EmptyFabric ef;
	curTile->setObject(ef.createObj(' '));
	swap(curTile->getObjectRef(), otherTile->getObjectRef());
	curTile->notify();
	return curTile;
}

void Tile::notify() {
	for (int i = 0; i < subscribers.size(); i++) {
		subscribers[i]->update();
	}
}