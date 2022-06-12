#include "player.h"

player::player(bool pos)
{
	position = pos; //false = 1, true = 2
}

player::~player()
{
	ReleaseDC(myconsole, mydc);
}

void player::MovePlayer(bool direction) 
{
	if (direction == false)  //up
		changeInY -= 74;
	else //down
		changeInY += 74;

	if (changeInY < 0)
		changeInY = 0;
	else if (changeInY > 407)
		changeInY = 407;
}

void player::ShowPlayer()
{
	for (int y = 1 + changeInY; y <= 74 + changeInY; y++) {
		if (position == false) { //player 1
			for (int x = 1; x <= 10; x++)
				SetPixel(mydc, x, y, RGB(255, 255, 255));

		}
		else { //player 2
			for (int x = 950; x <= 960; x++)
				SetPixel(mydc, x, y, RGB(255, 255, 255));
		}
	}
}
