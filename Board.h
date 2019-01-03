#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <time.h>
#include <algorithm>
#include "Ship.h"
using namespace std;

class Board
{
    public:
        Board(); //constructor;

        void initBoard(); //initializes the empty game board
        void printBoard(); //prints the grid (or board)

        void fire(); //collects the user input to play
        bool checkHit(Ship); //checks if fire registers a hit or miss

        int getTurnCount(); //recalls the amount of turns passed
        void setTurnCount(); //modifies the turns passed, usually +1

        bool checkGame(Ship); //checks if gameOver==true;

        void readScores();
        void writeScores(string, int);

        void printLeaderboard();

        int setDifficulty();

        int xCor; //x coordinate of user fire
        int yCor; //y coordinate of user fire

        int turn; //turn will be iterated after every move
        char arr[9][9]; //generic array of board grid. array is 9x9.
                        //8x8 game space with 1 row and column of coordinate markers

        string playerName;
        int playerScore;

        Ship armada[4]; //={car, bat, des, cru}

        vector<int> scoresArr;
        vector<string> namesArr;
        //int scoresArr[5];
        //string namesArr[5];

    private:
        bool gameOver; //if all ships in armada are sunk

};

#endif // BOARD_H

/*
ORDER OF PLAY

check if there are any ships left
write intel if turn%3=0
receive a coordinate
register hits or misses
    if a ship is hit, print hit
        if a ship's hp is 0, print destroy
print the board
print ships remaining

*/
