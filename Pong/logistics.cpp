#include "logistics.h"

#include <iostream>

int logistics::player1Score = 0;
int logistics::player2Score = 0;

void logistics::drawTable() {
	int yShift = 0;

	for (int i = 0; i <= 6; i++) {
		for (int y = 0 + yShift; y < 41 + yShift; y++) {
			for (int x = 470; x <= 475; x++)
				SetPixel(mydc, x, y, RGB(255, 255, 255));
		}
		yShift += 70;
	}
}

void logistics::updateScore(bool player) {
	if (player == false)
		player1Score++;
	else
		player2Score++;
}

void logistics::showScore() {
	std::cout << "                          " << ((player1Score < 10) ? "0" : "") << player1Score;
	std::cout << "                                                              " << ((player2Score < 10) ? "0" : "") << player2Score;
}
