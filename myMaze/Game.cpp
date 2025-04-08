#include "Maze.h"
#include "Controller.h"
#include "MazeDrawer.h"
#include "Game.h"
#include "MyExceptions.h"
#include <iostream>
#include <fstream>

using namespace std;

void Game::run(string name) {
	int width, height;
	bool isRunning = true;
	fstream file;
	file.open(name);
	file >> width >> height;

	Maze mz(width, height);
	MazeDrawer mzd(mz);

	mzd.subscribeOnMaze();
	file >> mz;
	PlayerController pc(mz, mz.getPlayer());



	while (isRunning) {
		try {
			pc.doMove();
		}
		catch (Exception ex) {
			if (ex.getInfo() == FinishException().getInfo()) {
				system("cls");
				isRunning = false;
				cout << "FINISHED";
			}
		}
	}

	file.close();
}