#pragma once
#include "Player.h"
#include "Maze.h"

class Controller {
private:
	Player& obj;
public:
	Controller(Player& obj);

	Position getNextPos(Position currentPosiotion, char pressedKey);
	void doMovement(Position nextPos, Maze &m);
	char tileHandler(Maze& m, char pressedKey);
};