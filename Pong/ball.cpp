#include "ball.h"

void ball::ShowBall(int PlayerOuterlayerCoordinates[74])
{
	int xShift[2] = { 0, 0 }; //Beginning, Ending
	bool direction = false; //Descending, Ascending
	
	changeInY += yIncrementAmt;
	for (int y = 220 + changeInY; y <= 233 + changeInY; y++) {
		if (y <= 1) //ball hits y-bound border
			yIncrementAmt++;
		else if (y >= 465)
			yIncrementAmt--;

		for (int x = 470 + xShift[0] + changeInX; x <= 472 + xShift[1] + changeInX; x++) {
			SetPixel(mydc, x, y, RGB(255, 255, 255));

			for (int i = 0; i < 74; i++) {
				if (y == PlayerOuterlayerCoordinates[i] && (x == 10 || x == 950)) {  //Collision detection
					if (i <= 38) {
						yIncrementAmt -= 12;
						if(yIncrementAmt == 0)
							yIncrementAmt -= 12;
					}
					if (i <= 74 && i > 38) {
						yIncrementAmt += 12;
						if (yIncrementAmt == 0)
							yIncrementAmt += 12;
					}

					ballDirection = !ballDirection;
					MoveBall();
				}
			}

			if (x <= -2 || x >= 962) { //ball goes outside of x-bound border
				changeInX = 0;
				changeInY = 0;
				yIncrementAmt = 0;
				xShift[0] = 0;
				xShift[1] = 0;

				gameOver = true;
				//Sleep(1000);
			}
		}
		
		if (xShift[0] == -6 && direction == false) 
			direction = true;
		else if (direction == false) {
			xShift[0]--;
			xShift[1]++;
		}
		else if (direction == true) {
			xShift[1]--;
			xShift[0]++;
		}
	}
}

void ball::MoveBall()
{
	if (ballDirection == false) 
		changeInX -= 12;
	else 
		changeInX += 12;
}

