#pragma once
#include "Tile.h"

class Maze {
private:
	Tile** field;
	int width, height;
public:
	Maze();
	Maze(int width, int height);
	~Maze();

	void generateMaze();
	void printMaze(Position plPos, int range);

	int getWidth();
	int getHeight();

	Tile& getTile(Position pos);
};