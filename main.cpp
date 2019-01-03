#include "Board.h"
#include "Ship.h"
//#include "Board.cpp"
//#include "Ship.cpp"

#include <iostream>

using namespace std;

//turn progression
/*
check if game is over
    if it is, get the turn count
    print name and turn count to scores.txt
input fire
check fire
print hit or miss
update and print board
print ships remaining
increment turn count
*/

void turnProg(Board b)
{
    int d=b.setDifficulty();
    Ship c=b.armada[d-1];

    b.turn=0;

    b.printBoard();
    cout<<endl;

    int i=0;
    while(i<1)
    {
        if(c.isSunk==true)
        {
            cout<<"\n\tGAME OVER"<<endl;
            cout<<"\n Your score is:  "<<b.turn;
            cout<<"\n What is your name?  ";
            cin>>b.playerName;

            b.writeScores(b.playerName, b.turn);

            cout<<"would you like to view the leaderboard? (y/n)  ";
            char showLead;
            cin>>showLead;
            if(showLead=='y')
            {
                b.readScores();
                b.printLeaderboard();
            }

            i++;
        }
        else
        {
            b.fire();
            b.checkHit(c);
            if(b.checkHit(c)==true)
            {
                cout<<"\n\n\n\tHIT!\t"<<endl;
                c.isHit();
            }
            else
            {
                cout<<"\n\n\n\tMISS\t"<<endl;
            }

            b.printBoard();
            cout<<endl;
            c.printStatus();
            cout<<'\n'<<c.heading<<"  "<<c.xpos<<"  "<<c.ypos<<endl;

            b.turn++;
        }
    }
}



int main()
{
    Board b;
    turnProg(b);

    //b.writeScores("test", 2);
    //b.readScores();
    //b.printLeaderboard();
}
