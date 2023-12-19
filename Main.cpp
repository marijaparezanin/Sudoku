/*
    Main.cpp

    Basic menu for a Sudoku game

    Through commandline arguments are passed 3 files, userInput, userOutput and solutions. The user can choose
    to load up an empty/filled sudoku from the userInput file and solve/validate it. It can also request
    the program generate an empty sudoku. Afterward the sudoku can be solved by user or computer, and  computer
    solved sudokus will be writen to file. If the user wishes to solve the sudoku they can enter the file path
    to the txt file with their solutions, the program will review it and print out statistics.
    An infinite amount of games can be played.


    Author: Marija Parezanin
    Date: 20.12.2023
    email: marija.parezanin@mensa.ba
    F: FTN SIIT, SV1/2022
*/

#include <iostream>
#include <fstream>


#include "Sudoku.h"
#include "SudokuSolver.h"
#include "FileManagerSudoku.h"
#include "SudokuValidator.h"
#include "GenerateSudoku.h"

using namespace std;

//Holds the current sudoku
static Sudoku& sudoku = Sudoku::getInstance();
static SudokuValidator& validator = SudokuValidator::getInstance();


//since identical code appears twice I've placed it in this function
//reads user solution and compares it to a sudoku solved by my program
void userSolves() {
    string userOutputFile;
    cout << "\n----------------------------------------------------------------------" << endl;
    cout << "Enter the file path of your solution: ";
    cin >> userOutputFile;

    sudokuSolver(sudoku);
    bool areEqual = fms::readUserSolution(sudoku, userOutputFile);

    if (areEqual) {
        cout << "\n\t\All good!" << endl;
        sudoku.displayStats();
    }
    else {
        cout << "\n\t\tIncorrectly solved" << endl;
        sudoku.displayStats();
    }

    sudoku.incPlayedGames();
}

//identical code appears 3 times
//checks sudoku validity and prints gane statistic
void printValid() {
    if (validator.validate()) {
        cout << "\n\t\All good!" << endl;
        sudoku.displayStats();
    }
    else {
        cout << "\n\t\tIncorrectly solved" << endl;
        sudoku.displayStats();
    }
}

int main(int argc, char* argv[]) {
    //If no files have been passed
    if (argc != 3) {
        std::cerr << "Error: expected 3 file paths to be passed via commandline" << endl;
        return 0;
    }

    //argv[0] is program name
    string userInputFile = argv[1];
    string myFile = argv[2];

    cout << "----------------------Welcome to SudokuSphere!----------------------\n";
    int choice = 0;
    while(true){
        cout << "Do you want to play a:\n";
        cout << "\t1. Pre-made sudoku from file\n";
        cout << "\t2. A new generated sudoku\n\t: ";
        cin >> choice;

        if (choice == 1) {
            //Pre-made sudoku
            fms::readFile(sudoku, userInputFile);    //fms is a namespace for FileManagerSudoku
            cout << sudoku;
            sudoku.countOriginal();         //since the base sudoku has been set i can count the pre-filled fields



            if (sudoku.isSolved) {
                printValid();
            }
            else {
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "This sudoku hasnt been solved yet. Do you want to: \n";
                cout << "\t1. Try solving it\n";
                cout << "\t2. See the solution\n\t:";
                cin >> choice;


                if (choice == 1) {
                    //user solves
                    userSolves();
                }
                else {
                    //program solves
                    sudokuSolver(sudoku);
                    cout << sudoku;

                    printValid();
                    fms::writeFile(sudoku, userInputFile);
                }
            }
        }
        else {
            //TO DO generate sudoku
            generateBaseSudoku(sudoku, 10);
            sudoku.countOriginal();         //since the base sudoku has been set i can count the pre-filled fields


            cout << sudoku;
            //write sudoku base
            fms::writeFile(sudoku, myFile, false);
            

            cout << "\n----------------------------------------------------------------------" << endl;
            cout << "Do you want to: \n";
            cout << "\t1. Try solving it\n";
            cout << "\t2. See the solution\n\t:";
            cin >> choice;

            if (choice == 1) {
                //user solves
                userSolves();
            }
            else {
                //program solves
                sudokuSolver(sudoku);
                cout << sudoku;

                printValid();
                fms::writeFile(sudoku, myFile);
            }

        }

        cout << "\n----------------------------------------------------------------------" << endl;
        cout << "Do you want to keep playing?\n";
        cout << "\t1. Yes!\n";
        cout << "\t2. No, maybe some other time.\n\t: ";
        cin >> choice;

        if (choice == 2) {
            cout << "\nThank you for playing!\n";
            return 1;
        }
        else {
            cout << "\n----------------------------------------------------------------------" << endl;
            //+1 because the numGame is incremented when a completed Sudoku is written in the file, or called so
            cout << "\nRound "<<sudoku.getGameNum() + 1<<"!\n";
        }
    }
    return 0;
}