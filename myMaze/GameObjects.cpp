#include "GameObjects.h"

GameObject::GameObject(char texture) : texture(texture) {}
GameObject::GameObject(const GameObject& go) : texture(go.texture) {}

void GameObject::setTexture(char newTexture) {
	texture = newTexture;
}

char GameObject::getTexture() {
	return texture;
}


Player::Player(char texture, Position pos) : GameObject(texture), pos(pos), countOfCoin(0) {}
Player::Player(const Player& pl) : GameObject(pl.texture), pos(pl.pos), countOfCoin(pl.countOfCoin) {}

void Player::setPosition(Position newPos) {
	pos = newPos;
}

Position Player::getPosition() {
	return pos;
}

std::string Player::getType() {
	return "Player";
}

void Player::gotCoin() {
	countOfCoin++;
}

int Player::getCountOfCoin() {
	return countOfCoin;
}

void Player::setCountOfCoin(int newCountOfCoin) {
	countOfCoin = newCountOfCoin;
}

Empty::Empty(char texture) : GameObject(texture) {}
Empty::Empty(const Empty& empty) : GameObject(empty.texture) {}
std::string Empty::getType() { return "Empty"; }

Door::Door(char texture) : GameObject(texture) {}
Door::Door(const Door& Door) : GameObject(Door.texture) {}
std::string Door::getType() { return "Door"; }

Coin::Coin(char texture) : GameObject(texture) {}
Coin::Coin(const Coin& Coin) : GameObject(Coin.texture) {}
std::string Coin::getType() { return "Coin"; }

Wall::Wall(char texture) : GameObject(texture) {}
Wall::Wall(const Wall& Wall) : GameObject(Wall.texture) {}
std::string Wall::getType() { return "Wall"; }