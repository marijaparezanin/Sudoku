#include "SudokuSolver.h"

#include <iostream>
#include <string>

#include "Sudoku.h"

using namespace std;


bool rowCheck(int(&sudokuTable)[9][9], int row, int val) {
    for (int j = 0; j < 9; j++) {
        if (val == sudokuTable[row][j]) {
            return false;
        }
    }
    return true;
}

bool colCheck(int(&sudokuTable)[9][9], int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (val == sudokuTable[i][col]) {
            return false;
        }
    }
    return true;
}

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

pair<int, int> findEmpty(int(&sudokuTable)[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudokuTable[i][j] == 0) {
                return { i, j };
            }
        }
    }
    return { -1, -1 };
}

//arrays are passed by reference by default
bool sudokuSolver(Sudoku& s) {
    pair<int, int> unassigned = findEmpty(s.sudokuTable);
    int i = unassigned.first;
    int j = unassigned.second;
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