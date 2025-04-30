#include "Maze.h"
#include "GameObjects.h"
#include "Tile.h"
#include "MyExceptions.h"
#include "Fabric.h"
#include <sstream>

using namespace std;


Maze::Maze(int width, int height) : width(width), height(height), mazeCountCoin(0) {
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
	std::ostringstream buffer;
	buffer << "\x1B[2J\x1B[H";

	for (int y = 0; y < maze.getHeight(); y++) {
		for (int x = 0; x < maze.getWidth(); x++) {
			buffer << maze.getTile(x, y)->getObject()->getTexture() << " ";
		}
		buffer << '\n';
	}
	buffer << "Coins : " << maze.getPlayer()->getCountOfCoins() << endl;
	buffer << "Healths : " << maze.getPlayer()->getHp() << endl;
	os << buffer.str();
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
			else if (tempTexture == 'M') {
				maze.setMonster(static_pointer_cast<Monster>(maze.getTile(x, y)->getObject()));
			}
			else if (tempTexture == '0') maze.addCoin();
		}
	}
	maze.getTile(0, 0)->notify();
	return is;
}



void Maze::movePlayer(char key) {

	int x = player->getX();
	int y = player->getY();

	switch (key) {
	case 'w':
		y -= 1;
		break;
	case 'a':
		x -= 1;
		break;
	case 's':
		y += 1;
		break;
	case 'd':
		x += 1;
		break;
	}
	try {
		field[y][x] += field[player->getY()][player->getX()];
		player->setX(x);
		player->setY(y);
	}
	catch (Exception ex) {
		if (ex.getInfo() == WallException().getInfo()) return;
		else if (ex.getInfo() == CoinException().getInfo()) {
			shared_ptr<Tile> t = field[y][x];
			t -= field[player->getY()][player->getX()];
			player->setX(x);
			player->setY(y);
			player->gotCoin();
			t->notify();
		}
		else if (ex.getInfo() == DoorException().getInfo()) {
			if (player->getCountOfCoins() == mazeCountCoin) {
				throw FinishException();
			}
		}
		return;
	}
}

void Maze::moveMonsters() {
	for (shared_ptr<Monster> monster : monsters) {
		int x = monster->getX();
		int y = monster->getY();

		int direction = rand() % 4;

		switch (direction)
		{
		case 0:
			y -= 1;
			break;
		case 1:
			x -= 1;
			break;
		case 2:
			y += 1;
			break;
		case 3:
			x += 1;
			break;
		}

		try {
			field[y][x] += field[monster->getY()][monster->getX()];
			monster->setX(x);
			monster->setY(y);
		}
		catch (Exception ex) {
			if (ex.getInfo() == PlayerHitException().getInfo()) {
				player->takeAwayHp(monster->getDamage());
				if (player->getHp() <= 0) throw PlayerDeathException(); // abort () 
			}
			continue;
		}
	}
}

void Maze::setMonster(shared_ptr<Monster> _monster) {
	monsters.push_back(_monster);
}

void Maze::addCoin() { mazeCountCoin++; }