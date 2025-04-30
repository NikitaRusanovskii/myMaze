#include "MazeDrawer.h"
#include "Tile.h"
#include "Maze.h"
#include "GameObjects.h"
#include <cmath>
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

void PlayerInfoDrawer::subscribe(std::shared_ptr<Tile> observable) {
	observable->getSubs().push_back(make_shared<PlayerInfoDrawer>(*this));
}

void PlayerInfoDrawer::update() {
	maze.drawPlayerInfo();
}

void PlayerInfoDrawer::subscribeOnMaze() {
	for (int y = 0; y < maze.getField().size(); y++) {
		for (int x = 0; x < maze.getField()[y].size(); x++) {
			subscribe(maze.getField()[y][x]);
		}
	}
}

void PlayerFOVDrawer::subscribe(std::shared_ptr<Tile> observable) {
	observable->getSubs().push_back(make_shared<PlayerFOVDrawer>(*this));
}

void PlayerFOVDrawer::update() {
	maze.drawPlayerFOV();
}

void PlayerFOVDrawer::subscribeOnMaze() {
	for (int y = 0; y < maze.getField().size(); y++) {
		for (int x = 0; x < maze.getField()[y].size(); x++) {
			subscribe(maze.getField()[y][x]);
		}
	}
}


