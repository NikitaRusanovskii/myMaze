#pragma once

class Position {
private:
	int x, y;
public:
	Position();
	Position(int x, int y);

	void setPosition(int newX, int newY);

	int getX();
	int getY();

};