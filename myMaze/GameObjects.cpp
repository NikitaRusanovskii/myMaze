#include "GameObjects.h"

GameObject::GameObject(char texture) : texture(texture) {}
GameObject::GameObject(const GameObject& go) : texture(go.texture) {}

void GameObject::setTexture(char newTexture) {
	texture = newTexture;
}

char GameObject::getTexture() {
	return texture;
}


Player::Player(char texture,Position pos) : GameObject(texture), pos(pos), countOfCoin(0), hp(10), weapon(new Hand()) {}
Player::Player(const Player& pl) : GameObject(pl.texture), pos(pl.pos), countOfCoin(pl.countOfCoin),
hp(pl.hp), weapon(pl.weapon) {}

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

int Player::getHp() { 
	return hp;
}

void Player::setHp(int _hp) { hp = _hp; }

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

Item::Item(int damage, int range,
	std::string target) : damage(damage), range(range), target(target) {}

Item::Item(const Item& item) : damage(item.damage), range(item.range), target(item.target) {}

int Item::getDamage() {
	return damage;
}

int Item::getRange() {
	return range;
}

std::string Item::getTarget() {
	return target;
}

Sword::Sword(int damage, int range,
	std::string target) : Item(damage, range, target) {
}

Sword::Sword(const Sword& sword) : Item(sword.damage, sword.range, sword.target) {}

std::string Sword::getType() {
	return "Sword";
}

// * ---------------------------------


Monster::Monster(char texture, Position pos) : GameObject(texture), pos(pos), hp(10), weapon(new Hand()) {}
Monster::Monster(const Monster& pl) : GameObject(pl.texture), pos(pl.pos),
hp(pl.hp), weapon(pl.weapon) {
}

void Monster::setPosition(Position newPos) {
	pos = newPos;
}

Position Monster::getPosition() {
	return pos;
}

std::string Monster::getType() {
	return "Monster";
}

int Monster::getHp() {
	return hp;
}

void Monster::setHp(int _hp) { hp = _hp; }

void Monster::doAttack(std::shared_ptr<Player> player) {
	player->setHp(player->getHp() - weapon->getDamage());
}