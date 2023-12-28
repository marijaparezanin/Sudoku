/*
    solverTest.cpp

    Tests various scenarios for the function that solves sudoku grids. 

    Author: Marija Parezanin
    Date: 27.12.2023
    email: marija.parezanin@mensa.ba
    F: FTN SIIT, SV1/2022

*/


#include "TestRunner.h"

#include <iostream>
#include "../Sudoku.h"
#include "../SudokuSolver.h"

using namespace std;


bool testEmptySolver() {
    // Initialize a Sudoku instance
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
    // Assign the empty grid to the Sudoku instance
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = initialValues[i][j];
        }
    }
    sudoku.countOriginal();
    // Solve the Sudoku
    sudokuSolver(sudoku);
    bool valid = sudoku.validate();
    if (valid && sudoku.getCorrectInputs() == 81 && sudoku.getOriginalInputs() == 0) {
        return true;
    }
    return false;
}

//solving a hard sudoku
bool testExtremeSolver() {
    // Initialize a Sudoku instance
    Sudoku sudoku = Sudoku::getInstance();


    int initialValues[9][9] = {
        {0, 6, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 7, 3, 0, 4, 0, 0},
        {4, 0, 0, 0, 0, 5, 9, 0, 0},
        {7, 0, 0, 9, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 8, 0, 0, 0},
        {0, 0, 0, 5, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 0, 5, 4, 0, 1, 6, 0, 3},
        {0, 3, 0, 6, 9, 7, 0, 0, 4}
    };


    sudoku.countOriginal();
    // Assign the empty grid to the Sudoku instance
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = initialValues[i][j];
        }
    }

    // Solve the Sudoku
    sudokuSolver(sudoku);
    bool valid = sudoku.validate();
    return valid;

}

//should return false if passed a sudoku it cant solve
bool testUnsolvableSudoku() {
    Sudoku sudoku = Sudoku::getInstance();

    int initialValues[9][9] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0},
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
    return result == false;
}

//it shouldnt return a mistake
bool testCompleteSudoku() {
    // Initialize a Sudoku instance
    Sudoku sudoku = Sudoku::getInstance();

    int initialValues[9][9] = {
        {3, 6, 9, 8, 2, 4, 5, 1, 7},
        {2, 5, 1, 7, 3, 9, 4, 8, 6},
        {4, 8, 7, 1, 6, 5, 9, 3, 2},
        {7, 2, 3, 9, 1, 6, 8, 4, 5},
        {5, 9, 6, 2, 4, 8, 3, 7, 1},
        {1, 4, 8, 5, 7, 3, 2, 6, 9},
        {6, 1, 4, 3, 5, 2, 7, 9, 8},
        {9, 7, 5, 4, 8, 1, 6, 2, 3},
        {8, 3, 2, 6, 9, 7, 1, 5, 4}
    };



    // Assign the empty grid to the Sudoku instance
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            sudoku.sudokuTable[i][j] = initialValues[i][j];
        }
    }

    sudoku.countOriginal();

    // Solve the Sudoku
    sudokuSolver(sudoku);
    bool valid = sudoku.validate();
    if (valid) {
        return true;
    }
    return false;
}

void displayTestSolver() {
    bool allTestsPassed = true;

    // Test valid Sudoku completion
    allTestsPassed &= testEmptySolver();

    allTestsPassed &= testExtremeSolver();

    allTestsPassed &= testUnsolvableSudoku();

    allTestsPassed &= testCompleteSudoku();


    if (allTestsPassed) {
        std::cout << "Solver tests passed!\n";
    }
    else {
        std::cout << "Some solver tests failed..\n";
    }
}