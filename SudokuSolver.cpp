/*
    SudokuSolver.cpp

    Solves an empty sudoku grid

    More detailed description in the header. sudokuSolver accepts an instance of Sudoku and directly solves the sudokuTable
    using backtracking, returns false if unsolveable. rowCheck, colCheck, boxCheck reviews if the value I wish to place is
    in accordance with the rules of Sudoku.


    Author: Marija Parezanin
    Date: 17.12.2023
    email: marija.parezanin@mensa.ba
    F: FTN SIIT, SV1/2022
*/

#include "SudokuSolver.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For rand
#include "Sudoku.h"
using namespace std;



//checks if the value i wish to place already exists in the row, accepts grid, which row to check and value to check for repetition
bool rowCheck(int(&sudokuTable)[9][9], int row, int val) {
    for (int j = 0; j < 9; j++) {
        if (val == sudokuTable[row][j]) {
            return false;
        }
    }
    return true;
}

//checks if the value i wish to place already exists in the column, accepts grid, which col to check and value to check for repetition
bool colCheck(int(&sudokuTable)[9][9], int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (val == sudokuTable[i][col]) {
            return false;
        }
    }
    return true;
}

//checks if the value i wish to place already exists in the 3x3 box, accepts grid, which row and column to check, and value to check for repetition
bool boxCheck(int(&sudokuTable)[9][9], int row, int col, int val) {
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudokuTable[r + i][c + j] == val) {
                return false;
            }
        }
    }
    return true;
}


/*
* Finds which empty cells have the fewest possible values, then among those who have the minimum num of possible values randomly
* chooses one to send back its coordinates. Returns {-1,-1} if no empty cells exist. 
* Implemented random choice so that when working with an empty grid its more random
*/
pair<int, int> findEmpty(int(&sudokuTable)[9][9]) {
    int minPossibilities = 10; // init with a value greater than possible options
    vector<pair<int, int>> minPossibilityCells;

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (sudokuTable[i][j] == 0) {
                int possibilities = 0;
                for (int num = 1; num <= 9; ++num) {
                    if (rowCheck(sudokuTable, i, num) && colCheck(sudokuTable, j, num) && boxCheck(sudokuTable, i, j, num)) {
                        possibilities++;
                    }
                }
                if (possibilities < minPossibilities) { //then i have a new standard for whats the minimum
                    minPossibilities = possibilities;
                    minPossibilityCells.clear();


                    //using emplace back instead of push back because constructing std::pair<int, int> directly within the vector
                    // is more efficient than creating temporary pairs before adding them to the vector.
                    minPossibilityCells.emplace_back(i, j);
                }
                else if (possibilities == minPossibilities) {
                    minPossibilityCells.emplace_back(i, j);
                }
            }
        }
    }

    // Randomly select one of the cells with the fewest possibilities using rand()
    if (!minPossibilityCells.empty()) {
        int randomIndex = rand() % minPossibilityCells.size();
        return minPossibilityCells[randomIndex];
    }

    return { -1, -1 }; // No empty cells found
}



//described in header, directly edits the multidimentional array in the passed sudoku object
bool sudokuSolver(Sudoku& s) {
    pair<int, int> empty = findEmpty(s.sudokuTable);
    int i = empty.first;
    int j = empty.second;

    //sudoku is already solved
    if (i == -1 && j == -1) {
        return true;
    }

    for (int num = 1; num <= 9;++num) {
        if (rowCheck(s.sudokuTable, i, num) && colCheck(s.sudokuTable, j, num) && boxCheck(s.sudokuTable, i, j, num)) {
            //gives warning because i and j could be -1, but have handled this scenario before array access
            s.sudokuTable[i][j] = num;

            if (sudokuSolver(s)) {
                return true;
            }

            s.sudokuTable[i][j] = 0;
        }
    }
    return false;
}