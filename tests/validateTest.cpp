#include "TestRunner.h"

#include <iostream>
#include "../Sudoku.h"

using namespace std;

bool testValidSudokuFilled() {
    Sudoku sudoku = Sudoku::getInstance();
    int solvedValues[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = solvedValues[i][j];
        }
    }

    bool result = sudoku.validate();

    return result == true;
}

bool testInvalidSudokuFilled() {
    Sudoku sudoku = Sudoku::getInstance();
    int solvedValues[9][9] = {
        {5, 3, 6, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = solvedValues[i][j];
        }
    }

    bool result = sudoku.validate();

    return result == false;
}

bool testValidIncompleteSudoku() {
    Sudoku sudoku = Sudoku::getInstance();

    int initialValues[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 6, 0, 0, 0, 0},
            {8, 0, 0, 0, 0, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = initialValues[i][j];
        }
    }

    bool result = sudoku.validate();    

    return result == true;
}

bool testInvalidIncompleteSudoku() {
    Sudoku sudoku = Sudoku::getInstance();

    int initialValues[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 6, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 6, 0, 0, 0, 0},
            {8, 0, 0, 0, 0, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = initialValues[i][j];
        }
    }

    bool result = sudoku.validate();

    return result == false;
}

bool testEmptySudoku() {
    Sudoku sudoku = Sudoku::getInstance();

    int initialValues[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = initialValues[i][j];
        }
    }

    // Validate the invalid Sudoku puzzle
    bool result = sudoku.validate();

    // Expected result for an invalid Sudoku is false
    return result == true;
}


void displayTestValidate() {
    // Perform tests
    bool allTestsPassed = true;

    // Test a correctly filled complete sudoku
    allTestsPassed &= testValidSudokuFilled();

    // Test an incorrectly filled complete sudoku
    allTestsPassed &= testInvalidSudokuFilled();

    // Test correctly filled incomplete sudoku
    allTestsPassed &= testValidIncompleteSudoku();

    // Test incorrectly filled incomplete sudoku
    allTestsPassed &= testInvalidIncompleteSudoku();

    //should say the empty correct is valid
    allTestsPassed &= testEmptySudoku();

    if (allTestsPassed) {
        std::cout << "Validator tests passed!\n";
    }
    else {
        std::cout << "Some validator tests failed..\n";
    }
}
