#pragma once
#include "Tile.h"

class Maze {
private:
	Tile field[10][10];
	int width, height;
public:
	Maze();
	Maze(int width, int height);
	
	void generateMaze();
	void printMaze(Position plPos, int range);

	int getWidth();
	int getHeight();

	Tile& getTile(Position pos);
};