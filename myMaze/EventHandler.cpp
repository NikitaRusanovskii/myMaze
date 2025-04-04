#include "EventHandler.h"

EventHandler::EventHandler(Maze& mz) : mz(mz) {}

PlayerEventHandler::PlayerEventHandler(Maze& mz, std::shared_ptr<Player> pl) :
	EventHandler(mz), pl(pl) {}

int PlayerEventHandler::onInteraction(Position objPos) {
	std::string type = mz.getTile(objPos)->getObj()->getType();
	if (type == "Wall") {
		return 0;
	}
	else if (type == "Coin") {
		pl->gotCoin();
		return 1;
	}
	else if (type == "Door") {
		if (pl->getCountOfCoin() >= 3) mz.toFinish();
		return 0;
	}
	else if (type == "Monster") {
		return 0;
	}
	else {
		return 3;
	}
}


MonsterEventHandler::MonsterEventHandler(Maze& mz, std::shared_ptr<Monster> monster) :
	EventHandler(mz), monster(monster) {
}

int MonsterEventHandler::onInteraction(Position objPos) {
	std::string type = mz.getTile(objPos)->getObj()->getType();
	if (type == "Empty") {
		return 1;
	}
	if (type == "Player") {
		return 2;
	}
	return 3;
}