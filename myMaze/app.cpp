#include "Maze.h"
#include "Player.h"
#include "Controller.h"
#include <conio.h>
#include <locale>
#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, " ");

	Maze m;
	Position plPos(1, 1);
	Player pl(plPos);
	Controller ct(pl);
	
	bool isRunning = true;
	char res, pressedKey;

	m.generateMaze();
	m.getTile(plPos).setContent(pl);
	
	while (isRunning) {
		m.printMaze(pl.getPosition(), 6);
		pl.printCountOfCoins();
		pressedKey = _getch();

		if (pressedKey == 'q') {
			isRunning = false;
		}

		res = ct.tileHandler(m, pressedKey);
		system("cls");
		if ((res == 'q')||(res == 'f')) isRunning = false;
	}

	if (res == 'f') cout << "!!! FINISHED !!!";

	return 0;
}