#include "Controller.h"
Controller::Controller(Player& obj) : obj(obj) {};

Position Controller::getNextPos(Position currentPosition, char pressedKey) {
	int ox = currentPosition.getX(),
		oy = currentPosition.getY();
	switch (pressedKey) {
	case 'w':
		oy -= 1;
		break;
	case 's':
		oy += 1;
		break;
	case 'a':
		ox -= 1;
		break;
	case 'd':
		ox += 1;
		break;
	}
	return Position(ox, oy);
}

void Controller::doMovement(Position nextPos, Maze &m) {
	m.getTile(obj.getPosition()).removeContent();
	obj.setPosition(nextPos);
	m.getTile(obj.getPosition()).setContent(obj);
}

char Controller::tileHandler(Maze& m, char pressedKey) {
	char result = ' ';
	Position nextPos = getNextPos(obj.getPosition(), pressedKey);
	switch (m.getTile(nextPos).getContent().getType()) {
	case 'w':
		return ' ';
	case 'c':
		obj.gotCoin();
		break;
	case 'd':
		if (obj.getCountOfCoins() >= 3) result = 'f';
		else return ' ';
		break;
	}
	doMovement(nextPos, m);
	return result;
}