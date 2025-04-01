#pragma once
#include "Position.h"
#include <string>

class GameObject {
protected:
	char texture;
public:
	GameObject(char texture);
	GameObject(const GameObject& go);

	void setTexture(char newTexture);
	char getTexture();

	virtual std::string getType() = 0;
};

class Player : public GameObject {
private:
	Position pos;
	int countOfCoin;
public:
	Player(char texture, Position pos);
	Player(const Player& pl);

	std::string getType() override;
	Position getPosition();
	void setPosition(Position newPos);
	void gotCoin();
	void setCountOfCoin(int newCountOfCoin);
	int getCountOfCoin();
};

class Empty : public GameObject {
public:
	Empty(char texture);
	Empty(const Empty& empty);
	std::string getType() override;
};

class Wall : public GameObject {
public:
	Wall(char texture);
	Wall(const Wall& wall);
	std::string getType() override;
};

class Coin : public GameObject {
public:
	Coin(char texture);
	Coin(const Coin& coin);
	std::string getType() override;
};

class Door : public GameObject {
public:
	Door(char texture);
	Door(const Door& door);
	std::string getType() override;
};