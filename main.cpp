/*

Written by Mohan Kancherla

CSCI 2312 final project due date Apr 08, 219

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>

// Including the header files
#include "PlayerShip.h"
#include "PlayerGrid.h"

using namespace std;

int main() 
{
	cout << "Hello!  Welcome to the Battleship Game of two Players " << endl;

	cout << " " << endl;

	cout << "Player 1 is you and player 2 is computer " << endl;

	cout << " " << endl;

	cout << "Following are the ships present in the game and their respective size\n"
		<< "Carrier - 5, Battleship - 4, Cruiser - 3, Submarine - 3, Destroyer - 2 \n" << endl;

	cout << "Starting the Game ! All the best" << endl;

	cout << "----------------------------------------------" << endl;
	cout << "----------------------------------------------" << endl;

	ships typeship;
	ShipGrids playerShipGrids;

    srand(time(NULL));

	//opening the file ship placement and reading the data
    ifstream myfile;

	myfile.open("ship_placement.csv", ifstream::in);

	// if file is present , it will read the data and allots the ships
		int numY;
		string line;
		char y;

		//reading in ships
		while (!myfile.eof()) {
			getline(myfile, line, ',');
			if (line.empty()) {
				//for extra blank lines at the end
				break;
			}
			typeship.setshipType(line);
			// as per the ship type , assigning the size and representation
			if (line == "Carrier") {
				typeship.setshipLength(5);
				typeship.setshiprepresent('C');
			}
			else if (line == "Battleship") {
				typeship.setshipLength(4);
				typeship.setshiprepresent('B');
			}
			else if (line == "Cruiser") {
				typeship.setshipLength(3);
				typeship.setshiprepresent('R');
			}
			else if (line == "Submarine") {
				typeship.setshipLength(3);
				typeship.setshiprepresent('S');
			}
			else if (line == "Destroyer") {
				typeship.setshipLength(2);
				typeship.setshiprepresent('D');
			}

			//location of the ship
			getline(myfile, line, ',');
			typeship.setshipX(line[0]);
			y = line[1];
			//converting to int value
			numY = typeship.chartoint(y);
			typeship.setshipY(numY);

			//orientation of the ship either horizontal or vertical
			getline(myfile, line, '\n');
			typeship.setshipOrientation(line[0]);

			// if there are any ships overlapping, we will generate new location to those ships and continue the game
			while (playerShipGrids.shipIntersection(typeship.chartoint(typeship.getshipX()), typeship.getshipY(), typeship.getshipLength(), typeship.getshipOrientation())) {
				cout << "The Ship is overlapped and generating the new location to the overlapped ship " << typeship.getshipType() << endl;
				typeship.generaterandomX();
				typeship.generaterandomY();
			}

			playerShipGrids.ShipPlacement(typeship.chartoint(typeship.getshipX()), typeship.getshipY(), typeship.getshipLength(), typeship.getshipOrientation(), typeship.getshiprepresent());

		}
		// Player 1 ships display
		cout << "Player 1 ships: " << endl << playerShipGrids << endl;

		//Randomly assigning the ships for player computer
		ShipGrids shipsforcomputer;
		for (int i = 0; i < 5; i++) {
			//generating the random number and take it as orientation
			int randOrientation = rand() % 2;
			if (randOrientation == 0) {
				typeship.setshipOrientation('H'); // horizontal orientation
			}
			else {
				typeship.setshipOrientation('V'); // vertical orientation
			}

			//Assignment of random location
			typeship.generaterandomX();
			typeship.generaterandomY();

			// Assignment of name and size for the ship
			if (i == 0) {
				typeship.setshipType("Carrier");
				typeship.setshipLength(5);
				typeship.setshiprepresent('C');
			}
			else if (i == 1) {
				typeship.setshipType("Battleship");
				typeship.setshipLength(4);
				typeship.setshiprepresent('B');
			}
			else if (i == 2) {
				typeship.setshipType("Cruiser");
				typeship.setshipLength(3);
				typeship.setshiprepresent('R');
			}
			else if (i == 3) {
				typeship.setshipType("Submarine");
				typeship.setshipLength(3);
				typeship.setshiprepresent('S');
			}
			else if (i == 4) {
				typeship.setshipType("Destroyer");
				typeship.setshipLength(2);
				typeship.setshiprepresent('D');
			}

			// checking if there are any ships overlapped, if it is overlapped we will decrement the value of i and try it agian
			if (shipsforcomputer.shipIntersection(typeship.chartoint(typeship.getshipX()),
				typeship.getshipY(), typeship.getshipLength(), typeship.getshipOrientation()))
			{
				i--;
			}
			else
			{
				shipsforcomputer.ShipPlacement(typeship.chartoint(typeship.getshipX()),
					typeship.getshipY(), typeship.getshipLength(), typeship.getshipOrientation(),
					typeship.getshiprepresent());
			}
		}


		//starting the game by giving the option to fire torpedos on the other grid
		bool sink = false;
		//player 1 guess
		string playerguess;
		ShipGrids Trackingofplayer;
		char x;
		int numX, Value;

		while (!sink) {
			// entering the coordinates to attack on computer ship
			cout << "Enter the coordinates to attack (A-J, 1-10) on the computer grid, or 'k' to exit: " << endl;
			cin >> playerguess;
			if (playerguess != "k") {
				//Taking the guess values into X and Y variables
				x = playerguess[0];
				y = playerguess[1];
				//Checking the incorrect error location
				while ((x < 'A' || x > 'J') || (y < '0' || y > '9')) {
					cout << "Entered location is incorrect and out of range. Please enter again" << endl;
					cin >> playerguess;
					x = playerguess[0];
					y = playerguess[1];
				}
				numX = typeship.chartoint(x);
				Value = playerguess[2];
				// this to check for the entered value 10
				if (Value == '0') {
					numY = 9;
				}
				else {
					numY = typeship.chartoint(y);
				}

				//function to detect the ho=it or miss on the ship
				if (shipsforcomputer.shotormiss(numX, numY, Trackingofplayer)) {
					cout << "Computer ship got HIT! " << endl;
					//check win conditions
					if (Trackingofplayer.Check()) {
						cout << "You win the game!" << endl;
						sink = true;
					}
				}
				else {
					cout << "Shot is missed.... " << endl;
				}
				cout << Trackingofplayer << endl;

				//Start of computer turn to fire the torpedos
				typeship.generaterandomX();
				typeship.generaterandomY();

				//after generating the values , assigning them to the variables
				numX = typeship.chartoint(typeship.getshipX());
				numY = typeship.getshipY();

				// this is to make sure the computer guess is already the guessed one or shot one.
				// if that is the case, it will again generate deiffernet values
				while (playerShipGrids.Getvalue(numY, numX) == 'O' || playerShipGrids.Getvalue(numY, numX) == 'X')
				{
					typeship.generaterandomX();
					typeship.generaterandomY();

					numX = typeship.chartoint(typeship.getshipX());
					numY = typeship.getshipY();
				}
				//displaying the computer guess value
				cout << "Computer's guess: " << typeship.getshipX() << typeship.getshipY() + 1 << endl;
				// checking whether the fired torpedo got hit or miss on player ship
				if (playerShipGrids.shotormiss(numX, numY, playerShipGrids)) {
					cout << "Computer hit your ship with torpedpo!" << endl;
					//checcking the winning condition
					if (playerShipGrids.Check()) {
						cout << "computer won the battleship game!" << endl;
						sink = true;
					}
				}
				// if shot is missed
				else
				{
					cout << "Computer missed the shot..." << endl;
				}
				cout << playerShipGrids << endl;
			}
			else
			{
				cout << "User doesn't want to play the game. Hence exiting from the game" << endl;
				sink = true;
			}
		}
	
	system("pause");
	return 0;
}