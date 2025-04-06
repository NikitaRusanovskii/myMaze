#include "Fabric.h"


using namespace std;


shared_ptr<GameObject> MainFabric::createObj(char texture, int x, int y){
	if (texture == '0') return make_shared<Coin>('0');
	if (texture == 'w') return make_shared<Wall>('w');
	if (texture == '#') return make_shared<Door>('#');
	if (texture == 'H') return make_shared<Player>(x, y, 'H');
	else return make_shared<Empty>(' ');
}

shared_ptr<GameObject> EmptyFabric::createObj(char texture) {
	return make_shared<Empty>(' ');
}