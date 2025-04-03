#include "Controllers.h"
#include "EventHandler.h"
#include "GameObjectsFabric.h"
#include <iostream>
#include <ctime>

using namespace std;

Controller::Controller(Maze& mz) : mz(mz) {}

PlayerController::PlayerController(Maze& mz, shared_ptr<Player> player) : Controller(mz), player(player) {}
int PlayerController::keyHandler(char keyChar) {
	PlayerEventHandler peh(mz, player);
	Position nextPos = player->getPosition();
	switch (keyChar) {
	case 'w':
		nextPos.setY(nextPos.getY() - 1);
		break;
	case 'a':
		nextPos.setX(nextPos.getX() - 1);
		break;
	case 's':
		nextPos.setY(nextPos.getY() + 1);
		break;
	case 'd':
		nextPos.setX(nextPos.getX() + 1);
		break;
	}


	int event = peh.onInteraction(nextPos);
	if (event != 0) {
		move(nextPos);
	}
	return 0;
}

void PlayerController::move(Position nextPos) {
	mz.getTile(nextPos) += mz.getTile(player->getPosition());
	player->setPosition(nextPos);
}

MonsterController::MonsterController(Maze& mz, shared_ptr<Monster> monster) : Controller(mz), monster(monster) {}
Position MonsterController::calculateNextPosition(int direction) {
	Position nextPos;
	int mx = monster->getPosition().getX(), my = monster->getPosition().getY();
	switch (direction) {
	case 0:
		nextPos.setX(mx);
		nextPos.setY(my - 1);
		break;
	case 1:
		nextPos.setX(mx - 1);
		nextPos.setY(my);
		break;
	case 2:
		nextPos.setX(mx);
		nextPos.setY(my + 1);
		break;
	case 3:
		nextPos.setX(mx + 1);
		nextPos.setY(my);
		break;
	}
	return nextPos;
}

int MonsterController::handleEvent(Position nextPos) {
	MonsterEventHandler meh(mz, monster);
	int event = meh.onInteraction(nextPos) == 1;
	if (event == 1) {
		return 1;
	}
	else if (event == 2) {
		// attack
		return 2;
	}
	return 0;
}

void MonsterController::doMove() {
	srand(time(0));
	int direction = rand() % 4;
	Position nextPos = calculateNextPosition(direction);
	int codeOfTheEvent = handleEvent(nextPos);
	cout << codeOfTheEvent;
	if (codeOfTheEvent == 1) {
		mz.getTile(nextPos) += mz.getTile(monster->getPosition());
		monster->setPosition(nextPos);
	}
	else if (codeOfTheEvent == 2) {
		monster->doAttack(std::static_pointer_cast<Player>(mz.getTile(nextPos)->getObj()));
		cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	}
}