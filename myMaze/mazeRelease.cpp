#include "Maze.h"
#include "Coin.h"
#include "Wall.h"
#include "Door.h"
#include "math.h"
#include <string>
#include <iostream>


Maze::Maze(int width, int height) : width(width), height(height) {};
Maze::Maze() : width(10), height(10) {};

int Maze::getHeight() {
	return height;
}

int Maze::getWidth() {
	return width;
}

void Maze::generateMaze() {
	std::string maze[] = {
		"wwwwwwwwww",
		"w      w#w",
		"w wwww0w w",
		"w    w w w",
		"w w ww w w",
		"w w 0w w w",
		"w wwww w w",
		"w 0    w w",
		"w wwww   w",
		"wwwwwwwwww"
	};

	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (maze[y][x] == 'w') {
				this->field[y][x] = Tile(Position(x, y), Wall('w'));
			}
			else if (maze[y][x] == '0') {
				this->field[y][x] = Tile(Position(x, y), Coin('0'));
			}
			else if (maze[y][x] == '#') {
				this->field[y][x] = Tile(Position(x, y), Door('#'));
			}
			else {
				this->field[y][x] = Tile(Position(x, y), GameObject());
			}
		}
	}
}

void Maze::printMaze(Position plPos, int range) {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			if (sqrt((x - plPos.getX()) * (x - plPos.getX()) + (y - plPos.getY()) * (y - plPos.getY())) < range) {
				std::cout << this->field[y][x].getContent().getTexture() << " ";
			}
			else std::cout << " " << " ";
		}
		std::cout << "\n";
	}
}

Tile& Maze::getTile(Position pos) {
	return this->field[pos.getY()][pos.getX()];
}