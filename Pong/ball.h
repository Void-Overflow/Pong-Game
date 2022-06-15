#ifndef BALL_H
#define BALL_H

#include "windows.h"

class ball
{
private:
	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	int changeInY;
	int changeInX;

	int yIncrementAmt;
public:
	bool ballDirection; //left, right
	bool gameOver = false;

	void ShowBall(int PlayerOuterlayerCoordinates[74]);
	void MoveBall();
};

#endif