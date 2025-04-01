#include "GameObjectsFabric.h"

using namespace std;

shared_ptr<GameObject> WallFabric::createObj(Position pos) {
	return make_shared<Wall>('w');
}

shared_ptr<GameObject> CoinFabric::createObj(Position pos) {
	return make_shared<Coin>('0');
}

shared_ptr<GameObject> DoorFabric::createObj(Position pos) {
	return make_shared<Door>('#');
}

shared_ptr<GameObject> EmptyFabric::createObj(Position pos) {
	return make_shared<Empty>(' ');
}

shared_ptr<GameObject> PlayerFabric::createObj(Position pos) {
	return make_shared<Player>('H', pos);
}