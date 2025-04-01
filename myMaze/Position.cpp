#include "Position.h"


Position::Position(int x, int y) : x(x), y(y) {}
Position::Position(const Position& pos) : x(pos.x), y(pos.y) {}

void Position::setX(int newX) {
	x = newX;
}

void Position::setY(int newY) {
	y = newY;
}

int Position::getX() {
	return x;
}

int Position::getY() {
	return y;
}