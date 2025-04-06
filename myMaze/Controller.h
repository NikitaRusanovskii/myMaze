#pragma once
#include "__fwd.h"
#include <memory>


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
	PlayerController(Maze& maze, std::shared_ptr<Player> player);
	~PlayerController() = default;
	void doMove() override;
};