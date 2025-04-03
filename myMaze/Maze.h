#pragma once
#include "Tile.h"
#include <vector>

class Maze {
private:
	int width, height, FOV, finished = 0;
	std::vector<std::vector<std::shared_ptr<Tile>>> field;
	std::shared_ptr<Player> player;
	std::shared_ptr<Monster> mn;
public:
	Maze(int width, int height, int FOV);
	~Maze() = default;

	void toFinish();
	bool isFinished();

	std::shared_ptr<Tile> getTile(Position pos);
	std::shared_ptr<Monster> getMonster();
	std::shared_ptr<Player> getPlayer();
	friend std::ostream& operator << (std::ostream& os, const Maze& mz);
	friend std::istream& operator>>(std::istream& ifs, Maze& mz);
};