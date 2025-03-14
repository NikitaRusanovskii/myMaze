#pragma once
#include "GameObject.h"
#include "Position.h"

class Player : public GameObject {
private:
	Position pos;
	int coinCounter;
public:
	Player();
	Player(Position pos);

	void setPosition(const Position& newPos);
	Position getPosition();

	void gotCoin();
	int getCountOfCoins();
	void printCountOfCoins();
};