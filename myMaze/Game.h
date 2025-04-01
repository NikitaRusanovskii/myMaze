#pragma once
#include "Maze.h"
#include "Controllers.h"
#include <fstream>

class Game {
private:
	std::string path;
public:
	Game(std::string path);
	void run();
};