#pragma once
#include "Position.h"
#include <string>
#include <memory>

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

class Item {
protected:
	std::string target;
	int damage, range;
public:
	Item(int damage, int range, std::string target);
	Item(const Item& item);
	int getDamage();
	int getRange();
	std::string getTarget();
	virtual std::string getType() = 0;
};

class Sword : public Item {
public:
	Sword(int damage, int range, std::string target);
	Sword(const Sword& sword);
	std::string getType() override;
};

class Hand : public Item {
public:
	Hand() : Item(1, 1, "Monster") {}
	std::string getType() { return "Hand"; }
};

class Player : public GameObject {
private:
	Position pos;
	int countOfCoin, hp;
	Item* weapon;
public:
	Player(char texture, Position pos);
	Player(const Player& pl);
	~Player() { delete weapon; }

	std::string getType() override;
	Position getPosition();
	void setPosition(Position newPos);
	void gotCoin();
	void setCountOfCoin(int newCountOfCoin);
	int getCountOfCoin();
	int getHp();
	void setHp(int _hp);
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

class Monster : public GameObject {
private:
	Position pos;
	int hp;
	Item* weapon;
public:
	Monster(char texture, Position pos);
	Monster(const Monster& pl);
	~Monster() { delete weapon; }

	std::string getType() override;
	Position getPosition();
	void setPosition(Position newPos);
	int getHp();
	void setHp(int _hp);
	void doAttack(std::shared_ptr<Player> player);
};