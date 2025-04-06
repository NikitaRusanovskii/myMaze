#include "Maze.h"
#include "MazeDrawer.h"
#include <iostream>
#include <fstream>


using namespace std;


int main() {

	int width, height;
	fstream file;
	file.open("maze.txt");
	file >> width >> height;

	Maze mz(width, height);
	MazeDrawer mzd(mz);

	mzd.subscribeOnMaze();
	file >> mz;

	file.close();

	return 0;
}