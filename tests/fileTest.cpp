/*
    fileTest.cpp

    Tests various scenarios that can occur when reading sudoku from a file

    Author: Marija Parezanin
    Date: 27.12.2023
    email: marija.parezanin@mensa.ba
    F: FTN SIIT, SV1/2022

*/


#include "TestRunner.h"

#include <iostream>
#include "../Sudoku.h"
#include "../SudokuSolver.h"
#include "../FileManagerSudoku.h"

using namespace std;

//testing if the user solution has the original values from the base grid
bool testMatchingGrid(string setUpPath, string userInputPath) {
    Sudoku sudoku = Sudoku::getInstance();
    sudoku.resetGrid();
    //loading up the base grid
    readFile(sudoku, setUpPath);
    readFile(sudoku, userInputPath);


    return sudoku.matchesBaseGrid;
}

//testing if the user solution doesnt have the original values from the base grid
bool testNotMatchingGrid(string setUpPath, string userInputPath) {
    Sudoku sudoku = Sudoku::getInstance();
    sudoku.resetGrid();
    //loading up the base grid
    readFile(sudoku, setUpPath);
    readFile(sudoku, userInputPath);


    return !sudoku.matchesBaseGrid;
}

//when given an empty file it should just keep the sudoku all zeros
bool testPassedEmptyFile(string emptyPath) {
    Sudoku sudoku = Sudoku::getInstance();
    sudoku.resetGrid();
    readFile(sudoku, emptyPath);
    sudoku.countOriginal();

    return sudoku.getOriginalInputs() == 0;
}

bool testUnsolvedSudoku(string unsolvedFilePath) {
    Sudoku sudoku = Sudoku::getInstance();
    sudoku.resetGrid();
    readFile(sudoku, unsolvedFilePath);

    return !sudoku.isSolved;
}

bool testSolvedSudoku(string solvedFilePath) {
    Sudoku sudoku = Sudoku::getInstance();
    sudoku.resetGrid();
    readFile(sudoku, solvedFilePath);


    return sudoku.isSolved;
}

void displayTestFile() {
    bool allTestsPassed = true;

    allTestsPassed &= testMatchingGrid("tests//testFiles//setUp1.txt", "tests//testFiles//userSolution.txt");

    allTestsPassed &= testNotMatchingGrid("tests//testFiles//setUp1.txt", "tests//testFiles//userSolutionIncorrect.txt");
    
    allTestsPassed &= testPassedEmptyFile("tests//testFiles//emptyFile.txt");

    allTestsPassed &= testUnsolvedSudoku("tests//testFiles//unsolvedSudoku.txt");

    allTestsPassed &= testSolvedSudoku("tests//testFiles//solvedSudoku.txt");


    if (allTestsPassed) {
        std::cout << "File tests passed!\n";
    }
    else {
        std::cout << "Some file tests failed..\n";
    }
}
