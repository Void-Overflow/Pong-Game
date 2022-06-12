#include<iostream>
#include "player.h"

int main(){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    
    player player1(false);
    player player2(true);

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
        Sleep(50);
        system("cls");
    }

    
    std::cin.ignore();
    return 0;
}