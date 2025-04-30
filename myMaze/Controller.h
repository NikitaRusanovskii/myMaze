#pragma once
#include "__fwd.h"
#include <memory>
#include <vector>



class Controller {
protected:
	Maze& maze;
public:
	Controller(Maze& maze);
	~Controller() = default;
	virtual void doMove() = 0;
};


class PlayerController : public Controller {
private:
	std::shared_ptr<Player> player;
public:
	PlayerController(Maze& maze);
	~PlayerController() = default;
	void doMove() override;
};

class MonstersController : public Controller {
private:
	std::vector<std::shared_ptr<Monster>> monsters;
public:
	MonstersController(Maze& maze);
	~MonstersController() = default;
	void doMove() override;
};