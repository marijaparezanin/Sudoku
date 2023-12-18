#pragma once
#include <iostream>


/*
	Author: Marija Parezanin 
	Date: 18.12.2023
	
	Implementation of the Sudoku grid

	For every round of the game played, a designated instance of this class will be used to hold the current sudoku. I implemented the
	Singleton design pattern, to make sure I dont accidentally create more than one Sudoku instance. 
*/


class Sudoku
{
	//how many inputs did user get right
	int numCorrectInputs;
	int numPlayedGames;
	//how many filled numbers were in it originally
	//calculated when generating/reading from file
	int numOriginalInputs;

	

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

	void displayStats();
	int getGameNum();
	void resetStats();
};


std::ostream& operator<<(std::ostream& os, Sudoku& s);



