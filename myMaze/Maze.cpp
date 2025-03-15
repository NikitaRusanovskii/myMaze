#include "Maze.h"
#include "Coin.h"
#include "Wall.h"
#include "Door.h"
#include "math.h"
#include <string>
#include <iostream>


Maze::Maze(int width, int height) : width(width), height(height) {
	field = new Tile*[height];
	for (int i = 0; i < height; i++) {
		field[i] = new Tile[width];
	}
};
Maze::Maze() : width(10), height(10) {
	field = new Tile * [height];
	for (int i = 0; i < height; i++) {
		field[i] = new Tile[width];
	}
};

int Maze::getHeight() {
	return height;
}

int Maze::getWidth() {
	return width;
}

Maze::~Maze() {
	for (int i = 0; i < height; i++) {
		delete[] field[i];
	}
	delete[] field;
}

void Maze::generateMaze() {
	std::string maze[] = {
		"wwwwwwwwwwwwwwwwwwww",
		"w w#   0   w    w  w",
		"w wwwwwwww wwww w  w",
		"w       w       w  w",
		"w    w  ww w wwww  w",
		"w wwww  w  w       w",
		"w w0w   wwwwwwwww ww",
		"w w www w          w",
		"w w       w wwwwwwww",
		"w w w  ww    w     w",
		"w wwwwwww     w    w",
		"w          w   w   w",
		"w   www ww  w      w",
		"w   w    wwwwwwww  w",
		"w w wwww w      w  w",
		"w w  w   w  www wwww",
		"w w  w w   ww      w",
		"w wwww w   w  www ww",
		"w    w w   w  w0   w",
		"wwwwwwwwwwwwwwwwwwww",
	};

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
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
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (sqrt((x - plPos.getX()) * (x - plPos.getX()) + (y - plPos.getY()) * (y - plPos.getY())) < range) {
				std::cout << this->field[y][x].getContent().getTexture() << " ";
			}
			else std::cout << "+" << " ";
		}
		std::cout << "\n";
	}
}

Tile& Maze::getTile(Position pos) {
	return this->field[pos.getY()][pos.getX()];
}