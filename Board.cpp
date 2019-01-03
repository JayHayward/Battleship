#include "Board.h"
#include "Ship.h"

Board::Board()
{

    Ship car("Carrier", 5);
    Ship bat("Battleship", 4);
    Ship des("Destroyer", 3);
    Ship cru("Cruiser", 2);

    armada[0]=car;
    armada[1]=bat;
    armada[2]=des;
    armada[3]=cru;


    initBoard();
}

void Board::initBoard()
{
    char mander='~';

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            arr[i][j]=mander;
        }
    }

    char alpha='A';
    for(int a=1; a<9; a++)
    {
        arr[a][0]=alpha;
        alpha++;
    }

    char num='1';
    for(int b=1; b<9; b++)
    {
        arr[0][b]=num;
        num++;
    }

    arr[0][0]=' ';
}

void Board::printBoard()
{
    for(int k=0; k<9; k++)
    {
        for(int i=0; i<9; i++)
        {
            cout<<arr[i][k]<<" ";
        }
        cout<<'\n';
    }
}

void Board::fire()
//function that takes user input and validates it
{
    cout<<"Enter a coordinate, seperated by a comma \",\""<<endl;
    cout<<"For example, \"A,1\""<<endl;
    string input;
    cin>>input;
    int a=0;
    while(a==0) //loops until it receives a valid coordinate
    {
        if ((input.length()!=3)||((!isalpha(input[0])))||(input[1]!=',')||(!isdigit(input[2]))||(input[2])<1)
        {
            cout<<"Invalid coordinate. Please try again"<<endl;
            cin>>input;
        }

        else
        {
            if((input[0]>='a')&&(input[0]<='z'))
            {
                input[0]=input[0]-32; //lowercase -> capital
            }

            if(input[0]>'H')
            {
                input[0]='H';
            }

            //cout<<"valid"<<endl;
            a++;
        }
    }

    input[0]=input[0]-16;
    //cout<<input[0]<<'\t'<<input[2]<<endl;

    xCor=input[0]-48; //column //-48 makes it an int, not a char
    yCor=input[2]-48; //row

    arr[xCor][yCor]='X';

    /* something to check it it's already been used?
        if(arr[xCor][yCor]!='~'
            cout<<"Already been played, buddy"<<endl;
    */
}

bool Board::checkHit(Ship ship)
{
    if((ship.heading=='E')||(ship.heading=='W'))
    {
        if(ship.yArr[0]==yCor)
        {
            for(int i=0; i<ship.shipSize; i++)
            {
                if(ship.xArr[i]==xCor)
                {
                    ship.isHit();
                    arr[xCor][yCor]='X';
                    //cout<<'\n'<<"HIT!"<<'\n'<<endl;
                    return true;
                }
            }
            arr[xCor][yCor]='O'; //if xCor isn't in xArrs
            //cout<<'\n'<<"MISS"<<'\n'<<endl;
            return false;
        }
        arr[xCor][yCor]='O'; //if yCor != yArr[0]
        //cout<<'\n'<<"MISS"<<'\n'<<endl;
        return false;
    }

    if((ship.heading=='N')||(ship.heading=='S'))
    {
        if(ship.xArr[0]==xCor)
        {
            for(int i=0; i<ship.shipSize; i++)
            {
                if(ship.yArr[i]==yCor)
                {
                    ship.isHit();
                    arr[xCor][yCor]='X';
                    //cout<<'\n'<<"HIT!"<<'\n'<<endl;
                    return true;
                }
            }
            arr[xCor][yCor]='O'; //if yCor isn't in yArr
            //cout<<'\n'<<"MISS"<<'\n'<<endl;
            return false;
        }
        arr[xCor][yCor]='O'; //if xCor != xArr[0]
        //cout<<'\n'<<"MISS"<<'\n'<<endl;
        return false;
    }
}

bool Board::checkGame(Ship x)
{
    int z=1;

    for(int i=0; i<4; i++)
    {
        if(armada[i].getSunk()==false) //this part works
        {
            gameOver=false;
            cout<<"  ABC  ";
            z=0;
            return z;
            //return false;
        }
        else if(armada[i].getSunk()==true) //this part doesn't
        {
            gameOver=true;
            cout<<"  XYZ  ";
            z=1;
            return z;
            //return true;
        }
    }
}

int Board::setDifficulty()
{
    cout<<"What difficulty would you like to play? (1-4)  ";
    int d;
    cin>>d;

    return d;
}

void Board::readScores()
{
    ifstream file;
    file.open("scores.txt");
    string line;
    if(file)
    {
        int i=0;
        while(getline(file, line))
        {
            string names;
            string turns;
            int turnsInt;
            stringstream ss(line);

            getline(ss, names, '\t');
            getline(ss, turns, '\n');
            turnsInt=stoi(turns);

            namesArr.push_back(names);
            scoresArr.push_back(turnsInt);
            i++;
        }
    }
}

void Board::printLeaderboard()
{

    bool sorted=false;
    while(sorted==false)
    {
        sorted=true;
        for(int j=0; j<scoresArr.size()-1; j++)
        {
            if(scoresArr[j]>scoresArr[j+1])
            {
                swap(scoresArr[j], scoresArr[j+1]);
                swap(namesArr[j], namesArr[j+1]);
                sorted=false;
            }
        }
    }


    cout<<"\n\n\tLEADERBOARD\n";
    for(int i=0; i<5; i++)
    {
        cout<<'\t'<<namesArr[i]<<'\t'<<scoresArr[i]<<endl;
    }
}

void Board::writeScores(string playerName, int playerScore)
{
    string filename="scores.txt";
    ofstream file;
    file.open(filename, ios::app);

    if(file)
    {
        //cout<<"scores successfully opened \n";
        file<<playerName<<'\t'<<playerScore<<'\n';
        cout<<"\n\n";
    }

    file.close();
}

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
