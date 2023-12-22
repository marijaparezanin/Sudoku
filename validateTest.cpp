#include "Sudoku.h"
#include <iostream>

using namespace std;

bool testValidSudokuCompletion() {
    Sudoku sudoku = Sudoku::getInstance();
    int initialValues[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
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
    // Fill in a valid Sudoku puzzle (completely filled)
    // Here you would assign a valid filled Sudoku puzzle to sudokuTable manually for testing

    // Validate the Sudoku puzzle
    bool result = sudoku.validate();

    // Expected result for a valid completed Sudoku is true
    return result == true;
}

bool testIncompleteSudoku() {
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
    // Fill in an incomplete Sudoku puzzle (partially filled without errors)
    // Here you would assign a partially filled Sudoku puzzle to sudokuTable manually for testing

    // Validate the incomplete Sudoku puzzle
    bool result = sudoku.validate();    

    // Expected result for an incomplete Sudoku without errors is true
    return result == true;
}

bool testIncorrectSudoku() {
    Sudoku sudoku = Sudoku::getInstance();

    int initialValues[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 6, 0, 0, 6, 0},
            {8, 0, 0, 0, 0, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 4, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = initialValues[i][j];
        }
    }
    // Fill in an incomplete Sudoku puzzle (partially filled without errors)
    // Here you would assign a partially filled Sudoku puzzle to sudokuTable manually for testing

    // Validate the incomplete Sudoku puzzle
    bool result = sudoku.validate();

    // Expected result for an incomplete Sudoku without errors is true
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


int main1() {
    // Perform tests
    bool allTestsPassed = true;

    // Test valid Sudoku completion
    allTestsPassed &= testValidSudokuCompletion();

    // Test incomplete Sudoku
    allTestsPassed &= testIncompleteSudoku();

    //should say the empty correct is valid
    allTestsPassed &= testEmptySudoku();

    // Test invalid Sudoku
    allTestsPassed &= testIncorrectSudoku();

    if (allTestsPassed) {
        std::cout << "All tests passed successfully!\n";
    }
    else {
        std::cout << "Some tests failed..\n";
    }

    return 0;
}
