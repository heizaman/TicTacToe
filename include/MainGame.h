#ifndef MAINGAME_H
#define MAINGAME_H

#include <string>


class MainGame
{
    public:
        MainGame();

        void startgame();
        void playgame();

    protected:

    private:
        char _board[3][3];

        std::string p1;
        std::string p2;

        char c1;
        char c2;

        void printboard();

        bool checkfull();
        char checkwin();

        bool mark(char c, int x, int y);

};

#endif // MAINGAME_H
