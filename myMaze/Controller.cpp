#include "Controller.h"
#include "GameObjects.h"
#include "MyExceptions.h"
#include "Maze.h"
#include "Tile.h"
#include <ctime>
#include <memory>
#include <random>
#include <conio.h>


using namespace std;


Controller::Controller(Maze& maze) : maze(maze) {}

PlayerController::PlayerController(Maze& maze) : Controller(maze) {}

void PlayerController::doMove() {
	char key = _getch();
	maze.movePlayer(key);
}


MonstersController::MonstersController(Maze& maze)  : Controller(maze) {}

void MonstersController::doMove() {
	maze.moveMonsters();
}