#ifndef LOGISTICS_H
#define LOGISTICS_H

#include <Windows.h>

class logistics
{
private:
	static int player1Score;
	static int player2Score;

	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);
public:
	void drawTable();

	void updateScore(bool player);
	void showScore();
};

#endif

