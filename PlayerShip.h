/*

written by Mohan Kancherla

CSCI 2312 final project due date Apr 08, 2019

*/

#ifndef BATTLESHIPGAME_PLAYERSHIP_H
#define BATTLESHIPGAME_PLAYERSHIP_H

#include <string>
// including the header file
#include "PlayerGrid.h"

using namespace std;

// defintion of ships class
class ships
{
private:
	// member variables
	char p;
	int q;
	char horizantalOrVertical;
	int lenth;
	char represent;
	string shiptype;

public:
	ships();// default destructor
	
	//declarations of accessor and mutator functions
    void setshipType(string shiptype);
    void setshipX(char p);
    void setshipY(int q);
    void setshipOrientation(char horizantalOrVertical);
    void setshipLength(int lenth);
    void setshiprepresent(char represent);

    string getshipType();
    char getshipX();
    int getshipY();
    char getshipOrientation();
    int getshipLength();
    char getshiprepresent();
	//function to convert char to int
    int chartoint(char p);
	// functionsto generate random x and y values
    void generaterandomX();
    void generaterandomY();
};
#endif //BATTLESHIPGAME_PLAYERSHIP_H
