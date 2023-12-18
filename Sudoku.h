/*	
	Sudoku.h

	Implementation of the Sudoku grid

	For every round of the game played, a designated instance of this class will be used to hold the current sudoku. I implemented the
	Singleton design pattern, to make sure I dont accidentally create more than one Sudoku instance. 

	
	Author: Marija Parezanin
	Date: 18.12.2023
	email: marija.parezanin@mensa.ba
	F: FTN SIIT, SV1/2022
	
*/

#pragma once
#include <iostream>




class Sudoku
{
	//how many inputs did user get wrong
	int numIncorrectInputs;
	int numPlayedGames;

	

	//private constructor and =, to make sure only the one instance exists
	Sudoku(): isSolved(true){}
	Sudoku& operator=(const Sudoku&);
	
public:
	//current sudoku
	int sudokuTable[9][9];
	bool isSolved;


	//even though this function can get called multiple times, only the one instance will exist
	static Sudoku& getInstance() {
		static Sudoku instance;
		return instance;
	}

	//self-explanitory
	void displayStats();
	int getGameNum();
	//increaces number of rounds played, resets rest to prepare for the new grid
	void resetStats();
};


//overriding system =, prints the sudoku grid in a "pretty" format. 
std::ostream& operator<<(std::ostream& os, Sudoku& s);



