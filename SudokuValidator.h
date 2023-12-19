/*
    SudokuValidator.h

    Class that checks the validity of a Sudoku

    Upon creation a private constructor is called (singleton design pattern), the linkedSudoku is initialized with the instance of Sudoku.
    It has 3 private functions that check if the 3 rules of sudoku are fulfilled. 
    Public validate function that returns true/false if the Sudoku is in accordance with the rules, and it also edits the statistical values
    of the Sudoku object. 

    Author: Marija Parezanin
    Date: 19.12.2023
    email: marija.parezanin@mensa.ba
    F: FTN SIIT, SV1/2022
*/

#pragma once
#include "Sudoku.h"

class SudokuValidator{
    //making sure that a change to the sudoku automatically changes the sudoku
    //i am not passing a reference to just the array because i also want to be updating the statistical paramathers
    Sudoku& linkedSudoku;

    bool rowCheck(int row, int position,  int val);
    bool colCheck(int col, int position, int val);
    bool boxCheck(int row, int col, int val);

    //making it private to reinforce singleton
    SudokuValidator() :linkedSudoku(Sudoku::getInstance()) {}
    Sudoku& operator=(const Sudoku&);
public:

    static SudokuValidator& getInstance() {
        static SudokuValidator instance;
        return instance;
    }

    bool validate();

};