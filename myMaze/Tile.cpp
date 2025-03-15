#include "Tile.h"

Tile::Tile(const Position& pos, const GameObject& content) : pos(pos), content(content) {};
Tile::Tile() : pos(Position()), content(GameObject()) {};
void Tile::setContent(const GameObject& newContent) {
	this->content = newContent;
}

void Tile::removeContent() {
	this->content = GameObject();
}

GameObject Tile::getContent() {
	return this->content;
}