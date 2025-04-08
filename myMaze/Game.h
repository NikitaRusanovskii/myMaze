#pragma once
#include "__fwd.h"
#include <string>


class Game {
public:
	Game() = default;
	~Game() = default;
	void run(std::string name);
};