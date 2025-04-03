#include "Game.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

Game::Game(string path) : path(path) {};

void Game::run() {

	fstream fl;
	int mazeWidth, mazeHeight, FOV;
	fl.open(path, fstream::in | fstream::out);
	fl >> mazeWidth >> mazeHeight >> FOV;
	Maze mz(mazeWidth, mazeHeight, FOV);
	fl >> mz;
	shared_ptr<Player> pl = mz.getPlayer();
	shared_ptr<Monster> mn = mz.getMonster();
	mz.getTile(pl->getPosition())->setObj(pl);
	PlayerController pc(mz, pl);

	MonsterController mc(mz, mn);

	while (!mz.isFinished()) {
		cout << mz;
		char key = _getch();
		if (key == 'q') {
			/*
			fl << mazeWidth << " " << mazeHeight << endl;
			fl << FOV << endl;
			fl << mz;
			fl << pl->getCountOfCoin();
			*/
			return;
		}

		mc.doMove();
		pc.keyHandler(key);

		system("cls");

	}

	cout << "FINISHED" << endl;
	fl.close();

}