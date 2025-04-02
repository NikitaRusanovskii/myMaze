#include "Controllers.h"
#include "EventHandler.h"
#include "GameObjectsFabric.h"

using namespace std;

Controller::Controller(Maze& mz) : mz(mz) {}

PlayerController::PlayerController(Maze& mz, shared_ptr<Player> player) : Controller(mz), player(player) {}
int PlayerController::keyHandler(char keyChar) {
	PlayerEventHandler peh(mz, player);
	Position nextPos = player->getPosition();
	switch (keyChar) {
	case 'w':
		nextPos.setY(nextPos.getY() - 1);
		break;
	case 'a':
		nextPos.setX(nextPos.getX() - 1);
		break;
	case 's':
		nextPos.setY(nextPos.getY() + 1);
		break;
	case 'd':
		nextPos.setX(nextPos.getX() + 1);
		break;
	}


	int event = peh.onInteraction(nextPos);
	if (event != 0) {
		move(nextPos);
	}
	return 0;
}

void PlayerController::move(Position nextPos) {
	mz.getTile(nextPos) += mz.getTile(player->getPosition());
	player->setPosition(nextPos);
}