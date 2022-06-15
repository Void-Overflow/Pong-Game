#ifndef PLAYER_H
#define PLAYER_H

#include<windows.h>

class player
{
private:
	bool position; 
	int changeInY = 222;

	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

public:
	int OuterCoordinates[74];

	player(bool pos);
	~player();

	void MovePlayer(bool direction);
	void ShowPlayer();

	void ResetPlayer();
};

#endif
