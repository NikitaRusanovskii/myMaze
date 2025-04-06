#include "Controller.h"
#include "GameObjects.h"
#include "Maze.h"
#include "Tile.h"
#include <memory>
#include <conio.h>


using namespace std;


Controller::Controller(Maze& maze) : maze(maze) {}

PlayerController::PlayerController(Maze& maze, shared_ptr<Player> player) : Controller(maze), player(player) {}

void PlayerController::doMove() {
	char key = _getch();
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
		maze.getTile(x, y) += maze.getTile(player->getX(), player->getY());
		player->setX(x);
		player->setY(y);
	}
	catch (int indexOfEvent) {
		if (indexOfEvent == 1) return;
		else if (indexOfEvent == 2) {
			maze.getTile(x, y) -= maze.getTile(player->getX(), player->getY());
			player->setX(x);
			player->setY(y);
			player->gotCoin();
		}
		else if (indexOfEvent == 3) {
			if (player->getCountOfCoins() == 3) {
				cout << "FINISHED";
			}
		}
		return;
	}
}

