/*
	FileManager.h

	Providing I/O services for the Sudoku class

	It always accepts file path and the sudoku object. It writes the sudoku Table to the file and resets the statistics.
	Whenever a sudoku is written to a file the number of rounds is incremented, and the other paramathers are set back to 0.
	There are 2 read functions, one is to read from the first file provided with argv, and the other reads from a file when
	a user is expected to provide their solution of the sudokuTable.


	Author: Marija Parezanin
	Date: 18.12.2023
	email: marija.parezanin@mensa.ba
	F: FTN SIIT, SV1/2022

*/

#pragma once
#include "Sudoku.h"


namespace fms {
	void readFile(Sudoku& s, std::string filePath);

	void writeFile(Sudoku& s, std::string filePath);

	void readUserSolution(Sudoku& s, std::string filePath);
}