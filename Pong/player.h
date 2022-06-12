#ifndef PLAYER_H
#define PLAYER_H

#include<windows.h>

class player
{
private:
	bool position; 
	int changeInY = 0;

	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

public:
	player(bool pos);
	~player();

	void MovePlayer(bool direction);
	void ShowPlayer();
};

#endif
