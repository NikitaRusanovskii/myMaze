#include "MainFabric.h"

std::shared_ptr<GameObject> MainFabric::createObj(char objChar, Position pos) {
	EmptyFabric ef;
	CoinFabric cf;
	WallFabric wf;
	DoorFabric df;
	PlayerFabric pf;
	if (objChar == '0') return cf.createObj(pos);
	if (objChar == 'w') return wf.createObj(pos);
	if (objChar == '#') return df.createObj(pos);
	if (objChar == 'H') return pf.createObj(pos);
	else return ef.createObj(pos);
}