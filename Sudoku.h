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
	int numPlayedGames;

	//private constructor and =, to make sure only the one instance exists
	Sudoku(): isSolved(true){}
	Sudoku& operator=(const Sudoku&);
	
protected:
	int numCorrectInputs;
	int numIncorrectInputs;
	int numOriginalInputs;
public:
	//current sudoku
	int sudokuTable[9][9];
	bool isSolved;
	int numEmptyInputs;



	//even though this function can get called multiple times, only the one instance will exist
	static Sudoku& getInstance() {
		static Sudoku instance;
		return instance;
	}

	//self-explanitory
	void displayStats();
	int getGameNum();
	void setInputs(int correctInputs, int emptyInputs);
	void setOriginalInputs(int originalInputs);

	//so i can differentiate how many fields user filled vs how many were alrady filled in the beginning
	void countOriginal();

	//increaces number of rounds played
	void incPlayedGames();
	//resets rest to prepare for the new grid
	void resetStats();
	//need reseting when im generating an empty sudoku
	void resetGrid();
};


//overriding system =, prints the sudoku grid in a "pretty" format. 
std::ostream& operator<<(std::ostream& os, Sudoku& s);
