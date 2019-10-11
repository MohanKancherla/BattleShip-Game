/*

Written by Mohan Kancherla

CSCI 2312 final project due date Apr 08,2019

*/

#ifndef BATTLESHIPGAME_PLAYERGRID_H
#define BATTLESHIPGAME_PLAYERGRID_H

#include <iostream>
// including the header file of playergrid file
#include "PlayerShip.h"

//defining the class shipgrid

using namespace std;

class ShipGrids
{
private:
	//member variables
    int rows;
    int columns;
    char ShipGridArray[10][10];
public:
	ShipGrids(); // default destructor
	// member functions
    void setposition(int y, int x, char val); //set position function
    char Getvalue(int y, int x); // function the get the values by position
	void ShipPlacement(int x, int y, int len, char orient, char representation); //ship placement function
	bool shipIntersection(int x, int y, int len, char orient); //function to check overlapped ships
	bool shotormiss(int x, int y, ShipGrids &gridtracking); // function to determine the shot miss or hit
	void shipsink(int y, int x, ShipGrids &gridtracking, char representation); // function to display which ship is sunk
    bool Check(); // function to check the number of hits required to win the game
	friend ostream& operator << (ostream &out, ShipGrids &ShipGrids);

};
#endif //BATTLESHIPGAME_PLAYERGRID_H
