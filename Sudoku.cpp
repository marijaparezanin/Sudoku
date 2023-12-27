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

#include "Sudoku.h"
#include <iostream>
#include <string>

using namespace std;


void Sudoku::resetGrid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudokuTable[i][j] = 0;
        }
    }
}


void Sudoku::resetStats() {
    numIncorrectInputs = 0;
    numCorrectInputs = 0;
}

void Sudoku::incPlayedGames() {
    numPlayedGames++;
}

//count the number of values that are filled in the base grid
void Sudoku::countOriginal() {
    numOriginalInputs = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudokuTable[i][j] != 0) {
                numOriginalInputs++;
            }
        }
    }
}


//inputs that already existed in the grid
void Sudoku::setOriginalInputs(int originalInputs) {
    this->numOriginalInputs = numOriginalInputs;
}

int Sudoku::getGameNum() {
    return numPlayedGames;
}

int Sudoku::getCorrectInputs() {
    return numCorrectInputs;
}

int Sudoku::getIncorrectInputs() {
    return numIncorrectInputs;
}

int Sudoku::getOriginalInputs() {
    return numOriginalInputs;
}

void Sudoku::displayStats() {
    //+1 because i display before I get to write to file. It would be dangerous to increment here
    cout << "\nGame played: " << numPlayedGames+1 << endl;
    //original is counted when the board is set, correct is counted in validate
    cout << "Correct inputs: " << numCorrectInputs << endl;
    cout << "Inorrect inputs: " << numIncorrectInputs << endl;

}

        
//return true if the sudoku has been filled well so far, accepts incomplete sudokus
bool Sudoku::validate() {
    numEmptyInputs = 0;
    numIncorrectInputs = 0;
    numCorrectInputs = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudokuTable[i][j] == 0) {
                numEmptyInputs++;
                continue;
            }
            else if (!rowCheck(i, j, sudokuTable[i][j]) || !colCheck(j, i, sudokuTable[i][j]) || !boxCheck(i, j, sudokuTable[i][j])) {
                numIncorrectInputs++;
                continue;
            }
            numCorrectInputs++;
        }
    }

    
    if (numIncorrectInputs != 0) {
        return false;
    }
    return true;
}


//checks if the value already exists in the row
//accepts in which row to look for duplicates of the value. Position is the postion of the value we're watching
bool Sudoku::rowCheck(int row, int position, int val) {
    for (int j = 0; j < 9; j++) {
        if (j != position && val == sudokuTable[row][j]) {
            return false;
        }
    }
    return true;
}

//checks if the value already exists in the column
//accepts in which column to look for duplicates of the value. Position is the postion of the value we're watching
bool Sudoku::colCheck(int col, int position, int val) {
    for (int i = 0; i < 9; i++) {
        if (i != position && val == sudokuTable[i][col]) {
            return false;
        }
    }
    return true;
}

//checks if the value already exists in the 3x3 box
//row and column are the coordinates of the value we're watching
bool Sudoku::boxCheck(int row, int col, int val) {
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(i == (row % 3) && j == (col % 3)) && sudokuTable[r + i][c + j] == val) {
                return false;
            }
        }
    }
    return true;
}


//making cout << sudoku have a pretty output
ostream& operator<<(std::ostream& os, Sudoku& s) {
    string content = "\n\t -------------------\n";
    for (int i = 0; i < 9;++i) {
        content += "\t |";
        for (int j = 0;j < 9;++j) {
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
    return os << content << endl;
}
