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


void Sudoku::resetStats() {
    numPlayedGames++;
    numIncorrectInputs = 0;
}



int Sudoku::getGameNum() {
    return numPlayedGames;
}

void Sudoku::displayStats() {
    cout << "\nGame played: " << numPlayedGames << endl;
    cout << "Incorrect inputs: " << numIncorrectInputs << endl;
}

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


