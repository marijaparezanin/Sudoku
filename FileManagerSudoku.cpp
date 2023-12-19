/*
	FileManager.h

	Providing I/O services for the Sudoku class. Can read sudoku from file, write sudoku to file, and read and confirm if a solution from a user file
	is what's expected.

	Author: Marija Parezanin
	Date: 18.12.2023
	email: marija.parezanin@mensa.ba
	F: FTN SIIT, SV1/2022

*/

#include "FileManagerSudoku.h"
#include "Sudoku.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


namespace fms {
	//read sudoku from file
	void readFile(Sudoku& s, std::string filePath) {
		ifstream ifile;
		ifile.open(filePath);


		if (!ifile) { // file couldn't be opened
			std::cerr << "Error: file could not be opened" << endl;
			return;
		}

		string line;
		int row_num = 0;
		while (true) {
			ifile >> line;
			if (row_num == 9) {
				return;
			}
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == '0') {
					s.isSolved = false;
				}
				s.sudokuTable[row_num][i] = line[i] - '0';
			}
			row_num++;
		}
	}

	//write sudoku to file, increment the number of games played
	void writeFile(Sudoku& s, std::string filePath, bool incGameNum) {
		ofstream ofile;
		ofile.open(filePath, std::ios::app);


		if (!ofile) { // file couldn't be opened
			std::cerr << "Error: file could not be opened" << endl;
			return;
		}

		std:string line = "\n\n";
		for (int i = 0; i < 9;i++) {
			for (int j = 0; j < 9; j++) {
				line += std::to_string(s.sudokuTable[i][j]);
			}
			ofile << line;
			line = "\n";
		}

		//because when the game is generated we write base+solution, but should inc once
		if (incGameNum) {
			s.incPlayedGames();
		}
		s.resetStats();
	}

	//read and confirm if a solution from a user file is what's expected in the sudoku object
	bool readUserSolution(Sudoku& s, std::string filePath) {
		ifstream ifile;
		ifile.open(filePath);


		if (!ifile) { // file couldn't be opened
			std::cerr << "Error: file could not be opened" << endl;
			return false;
		}

		string line;
		int row_num = 0;
		int numIncorrect = 0;
		while (true) {
			ifile >> line;
			if (row_num == 9) {
				break;
			}
			for (int i = 0; i < line.length(); i++) {
				if ((line[i] - '0') != s.sudokuTable[row_num][i]) {
					numIncorrect++;
				}
			}
			row_num++;
		}

		s.setInputs(81 - numIncorrect, 0);

		if (numIncorrect != 0) {
			return false;
		}
		return true;
		
	}
}