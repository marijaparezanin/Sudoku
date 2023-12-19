/*
	GenerateSudoku.h

	Generates a Sudoku base

	Accepts sudoku object whose grid it will fill with a "difficulty" amound of values. It first generates a solved sudoku before randomly
	removing values. It keeps in mind that there shouldn't be more than 6 values filled per box.

	Author: Marija Parezanin
	Date: 19.12.2023
	email: marija.parezanin@mensa.ba
	F: FTN SIIT, SV1/2022
*/

#pragma once
#include "Sudoku.h"

//places grid with difficulty amount of values filled in the sudokuTable of the passed Sudoku
void generateBaseSudoku(Sudoku& s, int difficulty);