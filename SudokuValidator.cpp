#include "SudokuValidator.h"
#include "Sudoku.h"


bool SudokuValidator::validate() {
    int numEmpty = 0;
    int numCorrectInputs = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (linkedSudoku.sudokuTable[i][j] == 0) {
                numEmpty++;
            }
            else if (rowCheck(i, j, linkedSudoku.sudokuTable[i][j]) && colCheck(j, i, linkedSudoku.sudokuTable[i][j]) && boxCheck(i, j, linkedSudoku.sudokuTable[i][j])) {
                numCorrectInputs++;
                continue;
            }
        }
    }

    linkedSudoku.setInputs(numCorrectInputs, numEmpty);


    if (numCorrectInputs + numEmpty != 81) {
        return false;
    }
    return true;
}


//checks if the value already exists in the row
bool SudokuValidator::rowCheck(int row, int position,  int val) {
    for (int j = 0; j < 9; j++) {
        if (j != position && val == linkedSudoku.sudokuTable[row][j]) {
            return false;
        }
    }
    return true;
}

//checks if the valuealready exists in the column
bool SudokuValidator::colCheck(int col, int position,  int val) {
    for (int i = 0; i < 9; i++) {
        if (i != position && val == linkedSudoku.sudokuTable[i][col]) {
            return false;
        }
    }
    return true;
}

//checks if the value already exists in the 3x3 box
bool SudokuValidator::boxCheck(int row, int col, int val) {
    int r = (row / 3) * 3;
    int c = (col / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(i == (row % 3) && j == (col % 3)) && linkedSudoku.sudokuTable[r + i][c + j] == val){
                return false;
            }
        }
    }
    return true;
}