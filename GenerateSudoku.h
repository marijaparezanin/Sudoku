/*
	GenerateSudoku.h

	Generates a Sudoku base

	Accepts sudoku object whose grid it will fill with a "difficulty" amound of values. It first generates a solved sudoku before randomly
	removing values.

	Author: Marija Parezanin
	Date: 19.12.2023
	email: marija.parezanin@mensa.ba
	F: FTN SIIT, SV1/2022

*/


#pragma once
#include "Sudoku.h"


void generateBaseSudoku(Sudoku& s, int difficulty);
