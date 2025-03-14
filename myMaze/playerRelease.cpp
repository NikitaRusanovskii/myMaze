#include "Player.h"
#include <iostream>

Player::Player() : pos(Position()), coinCounter(0), GameObject('H', 'p') {};
Player::Player(Position pos) : pos(pos), coinCounter(0), GameObject('H', 'p') {};

void Player::setPosition(const Position& newPos) {
	pos = newPos;
}

Position Player::getPosition() {
	return pos;
}

void Player::gotCoin() {
	this->coinCounter++;
}

void Player::printCountOfCoins() {
	std::cout << "I HAVE : " << this->coinCounter << " COINS!";
}

int Player::getCountOfCoins() {
	return this->coinCounter;
}