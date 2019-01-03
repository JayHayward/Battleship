#include <iostream>
#include <sstream>
#include <time.h>
#include "Ship.h"

using namespace std;

Ship::Ship()
{

}

Ship::Ship(string sName, int sSize)
{
    shipName=sName;
    shipSize=sSize;
    health=shipSize;
    isSunk=false;
    setHeading();
    setXpos();
    setYpos();

    for(int i=0; i<5; i++) //initial array filler
    {
        xArr[i]=-1;
        yArr[i]=-1;
    }

    if(heading=='E')
    {
        for(int i=0; i<shipSize; i++)
        {
            xArr[i]=xpos+i;
            yArr[0]=ypos;
        }
    }

    if(heading=='W')
    {
        for(int i=0; i<shipSize; i++)
        {
            xArr[i]=xpos-i;
            yArr[0]=ypos;
        }
    }

    if(heading=='S')
    {
        for(int i=0; i<shipSize; i++)
        {
            xArr[0]=xpos;
            yArr[i]=ypos+i;
        }
    }

    if(heading=='N')
    {
        for(int i=0; i<shipSize; i++)
        {
            xArr[0]=xpos;
            yArr[i]=ypos-i;
        }
    }
}

void Ship::setHeading()
{
    int xRan;
	srand(time(0));
	xRan=rand()%4+1;

	int i=0;
	while(i<1)
    {
        if(xRan==1)
        {
            heading='N';
            i++;
        }
        else if(xRan==2)
        {
            heading='E';
            i++;
        }
        else if(xRan==3)
        {
            heading='S';
            i++;
        }
        else if(xRan==4)
        {
            heading='W';
            i++;
        }
    }
}

void Ship::setXpos()
{
    if(heading=='E')
    {
        srand(time(0));
        xpos=rand()%(9-shipSize)+1; //checks out
    }
    else if(heading=='W')
    {
        srand(time(0));
        xpos=rand()%(9-shipSize)+shipSize;
    }
    else
    {
        srand(time(0));
        xpos=rand()%8+1;
    }
}

void Ship::setYpos()
{
    if(heading=='N')
    {
        srand(time(0));
        ypos=rand()%(9-shipSize)+shipSize;
    }
    else if(heading=='S')
    {
        srand(time(0));
        ypos=rand()%(9-shipSize)+1;
    }
    else
    {
        srand(time(0));
        ypos=rand()%8+1;
    }
}

char Ship::getHeading()
{
    return heading;
}

int Ship::getXpos()
{
    return xpos;
}

int Ship::getYpos()
{
    return ypos;
}

void Ship::isHit()
{
    health--;
    //cout<<"got hit\n";
    if(health==0)
    {
        isSunk=true;
    }
}

bool Ship::getSunk()
{
    return isSunk;
}

string Ship::getShipName()
{
    return shipName;
}

int Ship::getHealth()
{
    return health;
}

void Ship::setHealth(int x)
{
    health=x;
}

void Ship::printStatus() //loop this thru each type of ship
{
    /*
    for(int i=0; i<4; i++)
    {
        if(isSunk==false)
        {
            cout<<"ships remaining: "<<shipName<<endl;
        }
    }
    */

    cout<<shipName<<" health remaining:  "<<getHealth()<<endl;
}
