#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <time.h>
using namespace std;

class Ship
{
    public:
        Ship();
        Ship(string, int); //constructor. Name and size

        void printStatus(); //prints the name of a ship if that ship is remaining

        void isHit(); //if a shot connects, it prints "hit", health--

        void setHeading(); //direction from which the ship extends from its"base point"
        char getHeading(); //N/E/S/W

        void setXpos(); //random number
        int getXpos();
        void setYpos(); //random number
        int getYpos();

        string getShipName();

        int getHealth();
        void setHealth(int);

        bool getSunk();

        int shipSize; //length of the ship
        int xpos; //x position of the base element of ship
        //if heading is E/W
            //if size=2,xpos must be between index 2 and 7
            //if size=3,xpos must be between index 3 and 6
        int ypos; //y position of the base element of ship
        char heading; //N,E,S, or W. determines the direction of the ship

        bool isSunk; //whether the ship is sunk or not. Ship is sunk when health==0

        int xArr[5];
        int yArr[5];

    private:
        string shipName; //name of the ship. Carrier/Battleship/Destroyer/Cruiser
        int health; //hits left before it's destroyed
};

#endif
