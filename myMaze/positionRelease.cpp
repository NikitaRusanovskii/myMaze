#include "Position.h"

Position::Position() {
	this->x = -1;
	this->y = -1;

};

Position::Position(int x, int y) {
	this->x = x;
	this->y = y;
}

void Position::setPosition(int newX, int newY) {
	x = newX;
	y = newY;
}

int Position::getX() {
	return x;
}

int Position::getY() {
	return y;
}