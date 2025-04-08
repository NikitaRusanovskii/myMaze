#include "Controller.h"
#include "GameObjects.h"
#include "MyExceptions.h"
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
	catch (Exception ex) {
		if (ex.getInfo() == WallException().getInfo()) return;
		else if (ex.getInfo() == CoinException().getInfo()) {
			shared_ptr<Tile> t = maze.getTile(x, y);
			t -= maze.getTile(player->getX(), player->getY());
			player->setX(x);
			player->setY(y);
			player->gotCoin();
			t->notify();
		}
		else if (ex.getInfo() == DoorException().getInfo()) {
			if (player->getCountOfCoins() == 3) {
				throw FinishException();
			}
		}
		return;
	}
}

