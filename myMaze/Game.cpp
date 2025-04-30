#include "Maze.h"
#include "Controller.h"
#include "MazeDrawer.h"
#include "Game.h"
#include "MyExceptions.h"
#include <iostream>
#include <fstream>
#include <random>
#include <thread>
#include <chrono>

using namespace std;


void _moveMonsters(shared_ptr<MonstersController> mc) {
	while (true) {
		try {
			mc->doMove();
		}
		catch (Exception ex){
			if (ex.getInfo() == PlayerDeathException().getInfo()) {
				cout << "\033[2J\033[H";
				cout << "LOSER";
				exit(0);
			}
		}
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}
void Game::run(string name) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	srand(time(NULL));
	int width, height;
	bool isRunning = true;
	fstream file;
	file.open(name);
	file >> width >> height;

	Maze mz(width, height);
	MazeDrawer mzd(mz);
	PlayerFOVDrawer pfd(mz);
	PlayerInfoDrawer pid(mz);

	mzd.subscribeOnMaze();
	pfd.subscribeOnMaze();
	pid.subscribeOnMaze();

	file >> mz;
	file.close();
	PlayerController pc(mz);
	shared_ptr<MonstersController> mc = make_shared<MonstersController>(mz);

	thread monsterThread(_moveMonsters, mc);


	while (isRunning) {
		try {
			pc.doMove();
		}
		catch (Exception ex) {
			if (ex.getInfo() == FinishException().getInfo()) {
				cout << "\033[2J\033[H";
				isRunning = false;
				cout << "FINISHED";
			}
		}
	}
	monsterThread.detach();
}