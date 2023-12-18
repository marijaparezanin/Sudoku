#include "Sudoku.h"

#include <iostream>
#include <string>

using namespace std;

void Sudoku::resetStats() {
    numPlayedGames++;
    numCorrectInputs = 0;
    numOriginalInputs = 0;
}

/*
void Sudoku::displaySudoku() {
    string k = "";
    cout << "\t\n------------------\n";
    for (int i = 0; i < 9;++i) {
        for (int j = 0;j < 9;++j) {
            if (j % 3 == 2) {
                k = "|";
            }
            else {
                k = " ";
            }

            cout << "\t" << this->sudokuTable[i][j] << k;
        }
        if (i % 3 == 2) {
            k = "\n------------------\n";
        }
        else {
            k = "\n";
        }

        cout << k;
    }
}*/


int Sudoku::getGameNum() {
    return numPlayedGames;
}

void Sudoku::displayStats() {
    cout << "\nGame played: " << numPlayedGames << endl;
    cout << "Correct inputs: " << numCorrectInputs << endl;
    cout << "Incorrect inputs: " << 91 - numCorrectInputs - numOriginalInputs << endl;
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


