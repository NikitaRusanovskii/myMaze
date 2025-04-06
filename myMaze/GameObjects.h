#pragma once
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

class Entity : public GameObject {
protected:
	int x, y;
public:
	Entity(int x, int y, char texture);
	~Entity() = default;

	int getX();
	int getY();
	void setX(int _x);
	void setY(int _y);
};

class Player : public Entity {
private:
	int countOfCoins;
public:
	Player(int x, int y, char texture);
	~Player() = default;

	void setCountOfCoins(int cc);
	void gotCoin();
	int getCountOfCoins();

	std::string getType() override;

};

class Monster : public Entity {
public:
	Monster(int x, int y, char texture);
	~Monster() = default;
	std::string getType() override;
};