#include "Game.h"

/*
�������� �����������
�������� ������. mtx ��� ������������������ �������� <thread>. ��������� ��������� ��� ����� � ��� �� mutex
mutex �� <mutex>
*/

int main() {
	Game game("mamaze.txt");
	game.run();

	return 0;
}