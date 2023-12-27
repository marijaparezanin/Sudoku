/*
    generateTest.cpp

    Tests various scenarios for the function that generates a base grid sudoku grids.

    Author: Marija Parezanin
    Date: 27.12.2023
    email: marija.parezanin@mensa.ba
    F: FTN SIIT, SV1/2022

*/

#include "TestRunner.h"

#include <iostream>
#include "../Sudoku.h"
#include "../SudokuSolver.h"
#include "../GenerateSudoku.h"

using namespace std;

bool testGenerateEasy() {
    // Initialize a Sudoku instance
    Sudoku sudoku = Sudoku::getInstance();

    generateBaseSudoku(sudoku, 45);
    sudoku.countOriginal();
    bool isSolveable = sudokuSolver(sudoku);
    if (sudoku.getOriginalInputs() <= 45 && sudoku.getOriginalInputs() >= 40 && isSolveable) {
        return true;
    }
    return false;
}

bool testGenerateMedium() {
    // Initialize a Sudoku instance
    Sudoku sudoku = Sudoku::getInstance();

    generateBaseSudoku(sudoku, 40);
    sudoku.countOriginal();
    bool isSolveable = sudokuSolver(sudoku);
    if (sudoku.getOriginalInputs() <= 40 && sudoku.getOriginalInputs() >= 35 && isSolveable) {
        return true;
    }
    return false;
}

bool testGenerateHard() {
    // Initialize a Sudoku instance
    Sudoku sudoku = Sudoku::getInstance();

    generateBaseSudoku(sudoku, 35);
    sudoku.countOriginal();
    bool isSolveable = sudokuSolver(sudoku);
    if (sudoku.getOriginalInputs() <= 35 && sudoku.getOriginalInputs() >= 30 && isSolveable) {
        return true;
    }
    return false;
}

bool testGenerateExtreme() {
    // Initialize a Sudoku instance
    Sudoku sudoku = Sudoku::getInstance();

    generateBaseSudoku(sudoku, 20);
    sudoku.countOriginal();
    bool isSolveable = sudokuSolver(sudoku);
    if (sudoku.getOriginalInputs() <= 20 && sudoku.getOriginalInputs() >= 15 && isSolveable) {
        return true;
    }
    return false;
}

bool testGenerateInsane() {
    // Initialize a Sudoku instance
    Sudoku sudoku = Sudoku::getInstance();

    generateBaseSudoku(sudoku, 10);
    sudoku.countOriginal();
    bool isSolveable = sudokuSolver(sudoku);
    if (sudoku.getOriginalInputs() <= 10 && sudoku.getOriginalInputs() >= 5 && isSolveable) {
        return true;
    }
    return false;
}


void displayTestGenerate() {
    bool allTestsPassed = true;

    // Test valid Sudoku completion
    allTestsPassed &= testGenerateEasy();

    allTestsPassed &= testGenerateMedium();

    allTestsPassed &= testGenerateHard();

    allTestsPassed &= testGenerateExtreme();

    allTestsPassed &= testGenerateInsane();

    if (allTestsPassed) {
        std::cout << "Generator tests passed!\n";
    }
    else {
        std::cout << "Some generator tests failed..\n";
    }
}