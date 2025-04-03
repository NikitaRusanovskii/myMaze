#include "Game.h"

/*
добавить наблюдатель
добавить потоки. mtx для синхронизированния действий <thread>. Изменение лабиринта под одним и тем же mutex
mutex из <mutex>
*/

int main() {
	Game game("mamaze.txt");
	game.run();

	return 0;
}