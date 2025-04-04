#pragma once


class Position {
private:
	int x, y;
public:
	Position(int x = 0, int y = 0);
	Position(const Position& pos);

	int getX();
	int getY();

	void setX(int newX);
	void setY(int newY);
};