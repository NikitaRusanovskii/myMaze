#include "MazeDrawer.h"
#include "Tile.h"
#include "Maze.h"
#include <memory>
#include <iostream>


using namespace std;


void MazeDrawer::subscribe(std::shared_ptr<Tile> observable) {
	observable->getSubs().push_back(make_shared<MazeDrawer>(*this));
}

void MazeDrawer::update() {
	cout << maze;
}

void MazeDrawer::subscribeOnMaze() {
	for (int y = 0; y < maze.getField().size(); y++) {
		for (int x = 0; x < maze.getField()[y].size(); x++) {
			subscribe(maze.getField()[y][x]);
		}
	}
}