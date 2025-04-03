#pragma once
#include "Maze.h"

class Controller {
protected:
	Maze& mz;
public:
	Controller(Maze& mz);
	virtual int keyHandler(char keyChar) { return 0; };
};

class PlayerController : public Controller{
private:
	std::shared_ptr<Player> player;
public:
	PlayerController(Maze& mz, std::shared_ptr<Player> player);
	int keyHandler(char keyChar) override;
	void move(Position nextPos);
};

class MonsterController : public Controller {
private:
	std::shared_ptr<Monster> monster;
	Position calculateNextPosition(int direction);
public:
	MonsterController(Maze& mz, std::shared_ptr<Monster> monster);
	int handleEvent(Position nextPos);
	void doMove();
};