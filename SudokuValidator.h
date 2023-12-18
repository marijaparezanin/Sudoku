#pragma once
#include "Sudoku.h"
#include <iostream>



class SudokuValidator{
    //making sure that a change to the sudoku automatically changes the sudoku
    //i am not passing a reference to just the array because i also want to be updating the statistical paramathers
    Sudoku& linkedSudoku;

    bool rowCheck(int row, int position,  int val);
    bool colCheck(int col, int position, int val);
    bool boxCheck(int row, int col, int val);

    SudokuValidator() :linkedSudoku(Sudoku::getInstance()) {}
    Sudoku& operator=(const Sudoku&);
public:
    static SudokuValidator& getInstance() {
        static SudokuValidator instance;
        return instance;
    }

    bool validate();

};