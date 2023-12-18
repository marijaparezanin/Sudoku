/*
	SudokuSolver.h 

	Solves an empty sudoku grid

	It accepts a reference to a sudoku object and uses a backtracking algorithm to find appropriate values to fill the sudoku grid.
	The algorithm tries to place a value to the first available empty space, in case the value isn't fitting, it recursively calls
	on itself. It directly edits the multidimential array and returns false if the grid can't be solved.

	Author: Marija Parezanin
	Date: 17.12.2023
	email: marija.parezanin@mensa.ba
	F: FTN SIIT, SV1/2022
*/

#pragma once
#include "Sudoku.h"



//acceps a reference to the sudoku object and returns true/false if the grid is solveable
bool sudokuSolver(Sudoku& sudoku);

