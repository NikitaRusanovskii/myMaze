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