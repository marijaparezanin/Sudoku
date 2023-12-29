/*
	FileManager.h

	Providing I/O services for the Sudoku class. Can read sudoku from file, write sudoku to file, and read and confirm if a solution from a user file
	is what's expected.

	Author: Marija Parezanin
	Date: 22.12.2023
	email: marija.parezanin@mensa.ba
	F: FTN SIIT, SV1/2022

*/

#include "FileManagerSudoku.h"
#include "Sudoku.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//read sudoku from file on the passed path
void readFile(Sudoku& s, std::string filePath) {
	ifstream ifile;
	ifile.open(filePath);


	if (!ifile) { // file couldn't be opened
		throw std::invalid_argument("Provided file cant be opened");
		return;
	}

	string line;
	s.isSolved = true;
	s.matchesBaseGrid = true;

	int row_num = 0;
	int value = 0;
	while (true) {
		ifile >> line;
		if (row_num == s.sudokuSize || line == "") {
			return;
		}
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '0') {
				s.isSolved = false;
			}

			value = line[i] - '0';
			if (s.sudokuTable[row_num][i] == 0 || s.sudokuTable[row_num][i] == value) {
				s.sudokuTable[row_num][i] = value;
			}
			else {//if the original value of the base grid gets changed, the user is not solvinng the correct grid
				s.matchesBaseGrid = false;
			}

		}
		row_num++;
	}
}

//write sudoku to file
//accepts sudoku to write, file path to write to and whether the number of rounds should be incremented
void writeFile(Sudoku& s, std::string filePath, bool incGameNum) {
	ofstream ofile;
	ofile.open(filePath, std::ios::app);


	if (!ofile) { // file couldn't be opened
		throw std::invalid_argument("Provided file cant be opened");
		return;
	}

	string content = "\n\t -------------------\n";
	for (int i = 0; i < s.sudokuSize;++i) {
		content += "\t |";
		for (int j = 0;j < s.sudokuSize;++j) {
			//formating help
			if (j % 3 == 2) {
				if (s.sudokuTable[i][j] == 0) {
					content += " |";
				}
				else {
					content += std::to_string(s.sudokuTable[i][j]) + "|";
				}

			}
			else {
				if (s.sudokuTable[i][j] == 0) {
					content += "  ";
				}
				else {
					content += std::to_string(s.sudokuTable[i][j]) + " ";
				}
			}


		}
		if (i % 3 == 2) {
			content += "\n\t -------------------\n";
		}
		else {
			content += "\n";
		}

	}
	ofile << content;
	ofile << "\n\n";

	//because when the game is generated we write base+solution, but should inc once
	if (incGameNum) {
		s.incPlayedGames();
	}
	s.resetStats();
}

//for prettier solutions file, i write a line to split rounds
void writeEndOfRound(std::string filePath, int gameRound) {
	ofstream ofile;
	ofile.open(filePath, std::ios::app);

	if (!ofile) { // file couldn't be opened
		throw std::invalid_argument("Provided file cant be opened");
		return;
	}

	ofile << "---------------------------------------------------Round ";
	ofile << gameRound;
	ofile << "\n\n";
}
