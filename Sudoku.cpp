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


//self-explanatory
void Sudoku::resetGrid() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudokuTable[i][j] = 0;
        }
    }
}


//self-explanatory
void Sudoku::resetStats() {
    numIncorrectInputs = 0;
    numCorrectInputs = 0;
}

//self-explanatory
void Sudoku::incPlayedGames() {
    numPlayedGames++;
}


//self-explanatory
void Sudoku::setInputs(int correctInputs, int emptyInputs) {
    numCorrectInputs = correctInputs - numOriginalInputs;
    numIncorrectInputs = 81-emptyInputs-correctInputs;
    numEmptyInputs = emptyInputs;
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


bool Sudoku::validate() {
    int numEmpty = 0;
    int numCorrectInputs = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudokuTable[i][j] == 0) {
                numEmpty++;
            }
            else if (rowCheck(i, j, sudokuTable[i][j]) && colCheck(j, i, sudokuTable[i][j]) && boxCheck(i, j, sudokuTable[i][j])) {
                numCorrectInputs++;
                continue;
            }
        }
    }

    setInputs(numCorrectInputs, numEmpty);


    if (numCorrectInputs + numEmpty != 81 && numOriginalInputs+numEmpty != 81) {
        return false;
    }
    return true;
}


//checks if the value already exists in the row
bool Sudoku::rowCheck(int row, int position, int val) {
    for (int j = 0; j < 9; j++) {
        if (j != position && val == sudokuTable[row][j]) {
            return false;
        }
    }
    return true;
}

//checks if the valuealready exists in the column
bool Sudoku::colCheck(int col, int position, int val) {
    for (int i = 0; i < 9; i++) {
        if (i != position && val == sudokuTable[i][col]) {
            return false;
        }
    }
    return true;
}

//checks if the value already exists in the 3x3 box
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
std::ostream& operator<<(std::ostream& os, Sudoku& s) {
    std:string content = "\n\t -------------------\n";
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


