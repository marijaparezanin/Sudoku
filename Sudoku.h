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
	int numCorrectInputs;
	int numIncorrectInputs;
	int numOriginalInputs;	//fields that were filled in the base grid


	//private constructor and =, to make sure only the one instance exists
	Sudoku(): isSolved(true), matchesBaseGrid(true){}
	Sudoku& operator=(const Sudoku&);
public:
	//current sudoku
	int sudokuTable[9][9];
	bool isSolved;
	int numEmptyInputs;


	//in case of the user solution not matching the base grid
	bool matchesBaseGrid;


	//even though this function can get called multiple times, only the one instance will exist
	static Sudoku& getInstance() {
		static Sudoku instance;
		return instance;
	}

	//self-explanitory
	void displayStats();
	int getGameNum();
	int getCorrectInputs();
	int getIncorrectInputs();
	int getOriginalInputs();
	void setOriginalInputs(int originalInputs);

	//so i can differentiate how many fields user filled vs how many were alrady filled in the beginning
	void countOriginal();
	//increaces number of rounds played
	void incPlayedGames();
	//resets rest to prepare for the new grid
	void resetStats();
	//need reseting when im generating an empty sudoku
	void resetGrid();


	//checks if the value already exists in the row
	bool rowCheck(int row, int position, int val);
	//checks if the valuealready exists in the column
	bool colCheck(int col, int position, int val);
	//checks if the value already exists in the 3x3 box
	bool boxCheck(int row, int col, int val);
	//returns if the sudoku is filled correctly (even if it isnt completely filled)

	bool validate();

	//nothing to dellocate
	~Sudoku() {}
};


//overriding system =, prints the sudoku grid in a "pretty" format. 
std::ostream& operator<<(std::ostream& os, Sudoku& s);
