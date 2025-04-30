#pragma once
#include "__fwd.h"
#include <memory>


class Observer {
public:
	virtual void subscribe(std::shared_ptr<Tile> observable) = 0;
	virtual void update() = 0;
};

class MazeDrawer : public Observer {
private:
	Maze& maze;
public:
	MazeDrawer(Maze& maze) : maze(maze) {}
	virtual ~MazeDrawer() = default;
	void subscribe(std::shared_ptr<Tile> observable) override;
	void subscribeOnMaze();
	void update() override;
};

class PlayerFOVDrawer : public Observer {
private:
	Maze& maze;
public:
	PlayerFOVDrawer(Maze& maze) : maze(maze) {}
	virtual ~PlayerFOVDrawer() = default;
	void subscribe(std::shared_ptr<Tile> observable) override;

	void subscribeOnMaze();
	void update() override;
};

class PlayerInfoDrawer : public Observer {
private:
	Maze& maze;
public:
	PlayerInfoDrawer(Maze& maze) : maze(maze) {}
	virtual ~PlayerInfoDrawer() = default;
	void subscribe(std::shared_ptr<Tile> observable) override;

	void subscribeOnMaze();
	void update() override;
};
