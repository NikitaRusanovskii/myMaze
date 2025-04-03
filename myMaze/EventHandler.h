#pragma once
#include "Maze.h"

class EventHandler {
protected:
	Maze& mz;
public:
	EventHandler(Maze& mz);
	virtual int onInteraction(Position objPos) = 0;
};

class PlayerEventHandler : public EventHandler {
private:
	std::shared_ptr<Player> pl;
public:
	PlayerEventHandler(Maze& mz, std::shared_ptr<Player> pl);
	~PlayerEventHandler() = default;

	int onInteraction(Position objPos) override;
};

class MonsterEventHandler : public EventHandler {
private:
	std::shared_ptr<Monster> monster;
public:
	MonsterEventHandler(Maze& mz, std::shared_ptr<Monster> monster);
	~MonsterEventHandler() = default;

	int onInteraction(Position objPos) override;
};