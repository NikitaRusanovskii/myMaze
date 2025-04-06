#include "Maze.h"
#include "GameObjects.h"
#include "Tile.h"
#include "Fabric.h"

using namespace std;


Maze::Maze(int width, int height) : width(width), height(height) {
	field.resize(height, vector<shared_ptr<Tile>>(width));
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			field[y][x] = make_shared<Tile>();
		}
	}
}

std::shared_ptr<Tile> Maze::getTile(int x, int y) {
	return field[y][x];
}

void Maze::setTile(std::shared_ptr<Tile> tile, int x, int y) {
	field[y][x] = tile;
}

int Maze::getHeight() {
	return height;
}

int Maze::getWidth() {
	return width;
}

vector<vector<shared_ptr<Tile>>>& Maze::getField() {
	return field;
}

void Maze::setPlayer(shared_ptr<Player> _player) {
	player = _player;
}

shared_ptr<Player> Maze::getPlayer() {
	return player;
}

std::ostream& operator<<(std::ostream& os, Maze& maze) {
	system("cls");
	for (int y = 0; y < maze.getHeight(); y++) {
		for (int x = 0; x < maze.getWidth(); x++) {
			os << maze.getTile(x, y)->getObject()->getTexture() << " ";
		}
		os << '\n';
	}
	return os;
}

std::istream& operator>>(std::istream& is, Maze& maze) {
	char tempTexture;
	MainFabric mainFabric;
	for (int y = 0; y < maze.getHeight(); y++) {
		for (int x = 0; x < maze.getWidth(); x++) {
			is >> tempTexture;
			maze.getTile(x, y)->setObject(mainFabric.createObj(tempTexture, x, y));
			if (tempTexture == 'H') {
				maze.setPlayer(static_pointer_cast<Player>(maze.getTile(x, y)->getObject()));
			}
		}
	}
	maze.getTile(0, 0)->notify();
	return is;
}
