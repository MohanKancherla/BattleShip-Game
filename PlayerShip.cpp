/*

Written by Mohan Kancherla

CSCI 2312 final project due date Apr 08,2019

*/

// including the playership header file

#include "PlayerShip.h"

// defintion of default constructor
ships::ships() 
{
	shiptype = " ";
    p = ' ';
    q = 0;
	horizantalOrVertical = ' ';
    lenth = 0;
}

// defintions of setter functions
void ships::setshipOrientation(char horizantalOrVertical) 
{
    this->horizantalOrVertical = horizantalOrVertical;
}

void ships::setshipType(string shiptype)
{
	this->shiptype = shiptype;
}

void ships::setshipX(char p)
{
	this->p = p;
}

void ships::setshipY(int q) 
{
	this->q = q;
}

// defintion of conversion of char to int function
int ships::chartoint(char p) 
{ 
    int ValX = 0;

    if(p == 'A' || p == '1')
	{
		ValX = 0;
    }
	else if(p == 'B' || p == '2')
	{
		ValX = 1;
    }
	else if(p == 'C' || p == '3')
	{
		ValX = 2;
    }
	else if(p == 'D' || p == '4')
	{
		ValX = 3;
    }
	else if(p == 'E' || p == '5')
	{
		ValX = 4;
    }
	else if(p == 'F' || p == '6')
	{
		ValX = 5;
    }
	else if(p == 'G' || p == '7')
	{
		ValX = 6;
    }
	else if(p == 'H' || p == '8')
	{
		ValX = 7;
    }
	else if(p == 'I' || p == '9')
	{
		ValX = 8;
    }
	else
	{
		ValX = 9;
    }
    return ValX;
}

void ships::setshipLength(int lenth) {
    this->lenth = lenth;
}

// defintion of getter functions for shiptype, x-position, y-position
string ships::getshipType() {
    return this->shiptype;
}

char ships::getshipX() {
    return this->p;
}

int ships::getshipY() {
    return this->q;
}

// getter function for ship orientation either horizontal or vertical
char ships::getshipOrientation() {
    return this->horizantalOrVertical;
}

//getter function for ship length
int ships::getshipLength() 
{
    return this-> lenth;
}

//generating the random coordinate of value x(from A to J)
void ships::generaterandomX()
{
    int Xvalue = rand() % 10; 

    if(Xvalue == 0)
	{
        this->p = 'A';
    } 
	else if(Xvalue == 1)
	{
        this->p = 'B';
    } 
	else if(Xvalue == 2)
	{
        this->p = 'C';
    } 
	else if(Xvalue == 3)
	{
        this->p = 'D';
    } 
	else if(Xvalue == 4)
	{
        this->p = 'E';
    }
	else if(Xvalue == 5)
	{
        this->p = 'F';
    }
	else if(Xvalue == 6)
	{
        this->p = 'G';
    }
	else if(Xvalue == 7)
	{
        this->p = 'H';
    }
	else if(Xvalue == 8)
	{
        this->p = 'I';
    }
	else if(Xvalue == 9)
	{
        this->p = 'J';
    }
}

// generating the random coordinate of value y
void ships::generaterandomY() 
{
    int Yvalue = rand() %10; 
    this->q = Yvalue;
}

//setter function for ship representation
void ships::setshiprepresent(char represent)
{
    this->represent = represent;
}

//getter for reprenstation of ship
char ships::getshiprepresent() 
{
    return this->represent;
}


