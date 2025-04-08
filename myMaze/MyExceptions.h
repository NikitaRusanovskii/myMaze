#pragma once
#include <string>


class Exception {
private:
	std::string message;
public:
	Exception(std::string message);
	std::string getInfo();
};

class WallException : public Exception {
public:
	WallException() : Exception("the player hit a wall") {}
};

class CoinException : public Exception {
public:
	CoinException() : Exception("the player picked up the coin") {}
};

class DoorException : public Exception {
public:
	DoorException() : Exception("the player hit a door") {}
};

class FinishException : public Exception {
public:
	FinishException() : Exception("finished") {}
};