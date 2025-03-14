#pragma once
#include "Position.h"
#include "GameObject.h"

class Tile {
private:
	Position pos;
	GameObject content;
public:
	Tile();
	Tile(const Position& pos,const GameObject& content);

	void setContent(const GameObject& newContent);
	void removeContent();

	GameObject getContent();
};