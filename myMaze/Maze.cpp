#include "Maze.h"
#include "MainFabric.h"
#include <memory>
#include <math.h>
#include <iostream>

using namespace std;

Maze::Maze(int width, int height, int FOV) : width(width), height(height), FOV(FOV) {
	field.resize(height, vector<shared_ptr<Tile>>(width));
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			field[y][x] = make_shared<Tile>();
		}
	}
}

shared_ptr<Tile> Maze::getTile(Position pos) {
	return field[pos.getY()][pos.getX()];
}

shared_ptr<Player> Maze::getPlayer() {
	return player;
}

shared_ptr<Monster> Maze::getMonster() {
	return mn;
}

ostream& operator<<(ostream& os, const Maze& mz) {
	int px = mz.player->getPosition().getX();
	int py = mz.player->getPosition().getY();
	int dist;
	for (int y = 0; y < mz.height; y++) {
		for (int x = 0; x < mz.width; x++) {
			dist = sqrt((x - px) * (x - px) + (y - py) * (y - py));
			if ((int)dist <= mz.FOV) {
				os << mz.field[y][x]->getObj()->getTexture() << " ";
			}
		}
		if (abs(y - mz.player->getPosition().getY()) <= mz.FOV) {
			os << '\n';
		}
	}
	os << "Coins : " << mz.player->getCountOfCoin() << endl;
	os << "HP : " << mz.player->getHp();
	return os;
}

void Maze::toFinish() {
	finished = 1;
}

bool Maze::isFinished() {
	return (finished == 1) ? true : false;
}

istream& operator>>(istream& is, Maze& mz) {

	MainFabric mainFabric;
	char tempTexture;
	int coins;

	for (int y = 0; y < mz.height; y++) {
		for (int x = 0; x < mz.width; x++) {
			is >> tempTexture;
			mz.field[y][x]->setObj(mainFabric.createObj(tempTexture, Position(x, y)));

			if (mz.field[y][x]->getObj()->getType() == "Player") mz.player = static_pointer_cast<Player>(mz.field[y][x]->getObj());
			else if (mz.field[y][x]->getObj()->getType() == "Monster") mz.mn = static_pointer_cast<Monster>(mz.field[y][x]->getObj());

			mz.field[y][x]->setPosition(Position(x, y));
		}
	}
	is >> coins;

	mz.player->setCountOfCoin(coins);

	return is;
}