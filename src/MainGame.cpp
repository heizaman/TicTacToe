#include "MainGame.h"
#include <iostream>

using namespace std;




MainGame::MainGame()
{
    //ctor
}




void MainGame::printboard() {
    cout << endl;
    cout << "    1   2   3" << endl;
    cout << "  -------------" << endl
    ;
    for(int i=0; i<3; i++) {
        cout << i+1 << " | ";
        for(int j=0; j<3; j++) {
            cout << _board[i][j] << " | ";
        }
        cout << endl;
        cout << "  -------------";
        cout << endl;
    }
}




bool MainGame::checkfull() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(_board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

char MainGame::checkwin() {
    for(int i=0; i<3; i++) {
        if(_board[i][0]==_board[i][1] && _board[i][1]==_board[i][2] && _board[i][0]!=' ') {
            return _board[i][0];
        }
    }

    for(int i=0; i<3; i++) {
        if(_board[0][i]==_board[1][i] && _board[1][i]==_board[2][i] && _board[0][i]!=' ') {
            return _board[0][i];
        }
    }

    if(_board[0][0]==_board[1][1] && _board[1][1]==_board[2][2] && _board[0][0]!=' ') {
        return _board[0][0];
    }

    if(_board[0][2]==_board[1][1] && _board[1][1]==_board[2][0] && _board[1][1]!=' ') {
        return _board[1][1];
    }

    return '\0';
}




bool MainGame::mark(char c, int x, int y) {
    if(_board[x-1][y-1] != ' ' || x>3 || x<1 || y>3 || y<1)
        return false;
    _board[x-1][y-1] = c;
    return true;
}





void MainGame::startgame() {

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            _board[i][j] = ' ';
        }
    }

    cout << endl << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Enter the name of player 1: ";
    cin >> p1;
    cout << "Enter the name of player 2: ";
    cin >> p2;
    cout << "Enter the marker of " << p1 << ": ";
    cin >> c1;
    cout << "Enter the marker of " << p2 << ": ";
    cin >> c2;
}

void MainGame::playgame() {
    char c = c1;
    string p = p1;

    cout << checkwin();

    while(!checkwin() && !checkfull()) {
        printboard();
        int x;
        int y;
        bool marked = false;

        cout << endl << p << "'s turn!" << endl;

        while(!marked) {
            cout << "Enter the x coordinate of where you wish to place your marker: ";
            cin >> x;
            cout << "Enter the y coordinate of where you wish to place your marker: ";
            cin >> y;

            marked = mark(c, x, y);

            if(!marked) {
                cout << "Invalid marker location! Please try again!" << endl;
            }
        }

        if(p == p1) {
            c = c2;
            p = p2;
        }
        else {
            p = p1;
            c = c1;
        }
    }

    if(checkfull()) {
        cout << endl << "Game tied!";
    }
    else if(checkwin()){
        printboard();
        char winchar = checkwin();

        if(winchar == c1)
            cout << endl << p1 << " won!";
        else if(winchar == c2)
            cout << endl << p2 << " won!";
        else
            cout << "Unexpected error!";
    }
    else
        cout << "Unexpected error!";
}
