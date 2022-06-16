#include "player.h"
#include "ball.h"
#include "logistics.h"

int main(){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    
    player player1(false);
    player player2(true);

    ball ballobj;
    logistics data;

    while (true) {
        if (GetAsyncKeyState(0x57))
            player1.MovePlayer(false);
        else if (GetAsyncKeyState(0x53))
            player1.MovePlayer(true);

        if (GetAsyncKeyState(VK_UP))
            player2.MovePlayer(false);
        else if (GetAsyncKeyState(VK_DOWN))
            player2.MovePlayer(true);
        player1.ShowPlayer();
        player2.ShowPlayer();

        ballobj.MoveBall();
        if(ballobj.ballDirection == false)
            ballobj.ShowBall(player1.OuterCoordinates);
        else
            ballobj.ShowBall(player2.OuterCoordinates);

        if (ballobj.gameOver == true) {
            player1.ResetPlayer();
            player2.ResetPlayer();
            data.updateScore((ballobj.ballDirection) ? false : true);
            ballobj.gameOver = false;
        }

        data.drawTable();
        data.showScore();
        system("cls");
    }
    return 0;
}