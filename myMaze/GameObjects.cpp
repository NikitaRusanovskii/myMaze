#include "GameObjects.h"

GameObject::GameObject(char texture) : texture(texture) {}
GameObject::GameObject(const GameObject& go) : texture(go.texture) {}

void GameObject::setTexture(char newTexture) {
	texture = newTexture;
}

char GameObject::getTexture() {
	return texture;
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

Entity::Entity(int x, int y, char texture) : x(x), y(y), GameObject(texture){}

int Entity::getX() { return x; }
int Entity::getY() { return y; }

void Entity::setX(int _x) { x = _x; }
void Entity::setY(int _y) { y = _y; }

Player::Player(int x, int y, char texture) : Entity(x, y, texture), countOfCoins(0) {}

void Player::setCountOfCoins(int cc) {
	countOfCoins = cc;
}

int Player::getCountOfCoins() {
	return countOfCoins;
}

void Player::gotCoin() {
	countOfCoins++;
}

std::string Player::getType() { return "Player"; }

Monster::Monster(int x, int y, char texture) : Entity(x, y, texture) {}
std::string Monster::getType() { return "Monster"; }
