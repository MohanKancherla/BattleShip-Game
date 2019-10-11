/* 

Written by Mohan Kancherla

CSCI 2312 Final project due date Apr 08, 2019


*/

// including the header files 
#include "PlayerGrid.h"
#include "PlayerShip.h"

// default constructor definition
ShipGrids::ShipGrids() 
{
    rows = 10;
    columns = 10;
    for(int i =0; i < rows; i++){
        for(int j=0; j < columns; j++){
			ShipGridArray[i][j] = '@';
        }
    }
}

//calling the ship placement function
void ShipGrids::ShipPlacement(int x, int y, int len, char orient, char representation)
{
    if(!shipIntersection(x,y,len, orient))
	{
		//if the ship is in horizontal postion, it is added along the x-axis and y value will be same
        if(orient =='H') 
		{
            for (int i = x; i < x + len; i++) 
			{
                this->ShipGridArray[y][i] = representation;
            }
        }
		// if the ship orientation is vertical, it is added along the y-axis and x will be same
		else if(orient == 'V')
		{
            for(int i = y; i <y+len; i++)
			{
                this->ShipGridArray[i][x] = representation;
            }
        }
    } 
	// if ship is already present at that place we will display the following message
	else
	{
        cout << "A Ship is already present in that location" << endl;
    }
}

ostream	&operator<<(ostream &out, ShipGrids &ShipGrids)
{
    cout << "   ABCDEFGHIJ" << endl;
    for(int i = 0; i < ShipGrids.rows; i++)
	{
        if(i == 9)
		{ 
            cout << i + 1 << " ";
        } 
		else 
		{
            cout << i + 1 << "  ";
        }
        for(int j = 0; j < ShipGrids.columns; j++)
		{
           cout << ShipGrids.ShipGridArray[i][j];
        }
        cout << endl;
    }
    return out;
}


// function to check ship intersection and out of range values
bool ShipGrids::shipIntersection(int x, int y, int len, char orient) 
{
    if (orient == 'H') // horizontal direction
	{
        for(int i = x; i < x+len; i++)
		{
            if(this->ShipGridArray[y][i] != '@' ||  i > 9)
			{
                return true;
            }
        }
    } 
	else if(orient == 'V') // vertical direction
	{ 
        for (int i = y; i < y + len; i++) 
		{
            if (this->ShipGridArray[i][x] != '@' ||  i > 9) 
			{
                return true;
            }
        }
    }
    return false;
}


bool ShipGrids::shotormiss(int x, int y, ShipGrids &gridtracking) 
{
    bool hit = false;
    char representation;
    if(this->ShipGridArray[y][x] != '@' && this->ShipGridArray[y][x] != 'X' && this->ShipGridArray[y][x] != 'O')
	{
        //this case means grid array contains a ship at [y][x]
		representation = this->ShipGridArray[y][x];
		shipsink(y, x, gridtracking, representation);
        hit = true;
    } 
	else
	{
		gridtracking.setposition(y, x, 'O');
    }
    return hit;
}

void ShipGrids::setposition(int y, int x, char val) {
    this->ShipGridArray[y][x] = val;
}

//displaying which ship is drowned into water
void ShipGrids::shipsink(int y, int x, ShipGrids &gridtracking, char representation)
{
    if(representation == 'C')
	{
        cout << "The Carrier was sunk!" << endl;
    } 
	else if(representation =='B')
	{
        cout << "The Battleship was sunk!" << endl;
    } 
	else if(representation == 'R')
	{
        cout << "The Cruiser was sunk!" << endl;
    }
	else if(representation == 'S')
	{
        cout << "The Submarine was sunk!" << endl;
    } 
	else if(representation == 'D'){
        cout << "The Destroyer was sunk!" << endl;
    }

    //updating the grid values and tracking the grid
    int i =0;
    //if ship continues above y,x
    if(this->ShipGridArray[y-1][x] == representation){
        i = 0;
        while(this->ShipGridArray[y+i][x] == representation)
		{ 
			gridtracking.setposition(y + i, x, 'X');
            i--;
        }
        i = 1;
        while(this->ShipGridArray[y + i][x] == representation){
			gridtracking.setposition(y+i,x,'X');
            i++;
        }
    } else if(this->ShipGridArray[y+1][x] == representation){
        i = 0;
        while(this->ShipGridArray[y+i][x] == representation)
		{
			gridtracking.setposition(y + i, x, 'X');
            i--;
        }
        i = 1;
        while(this->ShipGridArray[y + i][x] == representation) {
			gridtracking.setposition(y + i, x, 'X');
            i++;
        }
    } 
	else if(this->ShipGridArray[y][x-1] == representation){
        i=0;
        while(this->ShipGridArray[y][x+i] == representation)
		{ 
			gridtracking.setposition(y,x+i,'X');
            i--;
        }
        i=1;
        while(this->ShipGridArray[y][x+i] == representation){
			gridtracking.setposition(y,x+i,'X');
            i++;
        }
    } else if(this->ShipGridArray[y][x+1] == representation) {
        i = 0;
        while (this->ShipGridArray[y][x + i] == representation) 
		{ 
			gridtracking.setposition(y, x + i, 'X');
            i--;
        }
        i = 1;
        while (this->ShipGridArray[y][x + i] == representation) {
			gridtracking.setposition(y, x + i, 'X');
            i++;
        }
    }
}

char ShipGrids::Getvalue(int y, int x) {
    return this->ShipGridArray[y][x];
}

//function to check the win number of shots
bool ShipGrids::Check() {
	int shots = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (this->ShipGridArray[i][j] == 'X')
			{
				// counting the total shots
				shots++;
			}
		}
	}
	return shots == 17;
}

