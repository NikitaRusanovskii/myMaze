#pragma once
#include "__fwd.h"
#include <iostream>
#include <vector>
#include <memory>

class Maze {
private:
	int width, height;
	std::shared_ptr<Player> player;
	std::vector<std::vector<std::shared_ptr<Tile>>> field;
public:
	Maze(int width, int height);
	~Maze() = default;

	std::shared_ptr<Tile> getTile(int x, int y);
	void setTile(std::shared_ptr<Tile> tile, int x, int y);

	std::vector<std::vector<std::shared_ptr<Tile>>>& getField();

	int getHeight();
	int getWidth();

	std::shared_ptr<Player> getPlayer();
	void setPlayer(std::shared_ptr<Player> _player);

};

std::istream& operator>>(std::istream& is, Maze& maze);
std::ostream& operator<<(std::ostream& os, Maze& maze);