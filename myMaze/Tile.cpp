#include "Tile.h"
#include "GameObjects.h"
#include "MazeDrawer.h"
#include <memory>
#include <vector>


using namespace std;

std::vector<std::shared_ptr<Observer>>& Observable::getSubs() {
	return subscribers;
}

Tile::Tile(shared_ptr<GameObject> object) : Observable(), object(object) {}
std::shared_ptr<GameObject> Tile::getObject() {
	return object;
}
void Tile::setObject(std::shared_ptr<GameObject> _object) {
	object = _object;
}

Tile& operator+=(Tile& curTile, Tile& otherTile) {
	return curTile;
}
Tile& operator-=(Tile& curTile, Tile& otherTile) {
	return curTile;
}

void Tile::notify() {
	for (int i = 0; i < subscribers.size(); i++) {
		subscribers[i]->update();
	}
}