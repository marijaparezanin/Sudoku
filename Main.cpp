/*
    Main.cpp

    Basic menu for a Sudoku game

    Through commandline arguments are passed two files, userInput and solutions. The user can choose
    to load up an empty/filled sudoku from the userInput file and solve/validate it. It can also request
    the program generate an empty sudoku. Afterward the sudoku can be solved by user or computer, and 
    solved sudokus will be writen to file. An infinite amount of games can be played.


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

using namespace std;



int main(int argc, char* argv[]) {
    //Holds the current sudoku
	Sudoku& sudoku = Sudoku::getInstance();
    SudokuValidator& validator = SudokuValidator::getInstance();

    //If no files have been passed
    if (argc == 1) {
        std::cerr << "Error: expected 2 file paths to be passed via commandline" << endl;
        return 0;
    }

    //argv[0] is program name
    string userFile = argv[1];
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
            fms::readFile(sudoku, userFile);    //fms is a namespace for FileManagerSudoku
            cout << sudoku;

            if (sudoku.isSolved) {
                if (validator.validate()) {
                    cout << "Correct!" << endl;
                    sudoku.displayStats();
                }
                cout << "Incorrectly solved" << endl;
                sudoku.displayStats();
            }
            else {
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "This sudoku hasnt been solved yet. Do you want to: \n";
                cout << "\t1. Try solving it\n";
                cout << "\t2. See the solution\n\t:";
                cin >> choice;


                if (validator.validate()) {
                    cout << "Correct!" << endl;
                    sudoku.displayStats();
                }
                cout << "Incorrectly solved" << endl;
                sudoku.displayStats();



                if (choice == 1) {
                    //user solves
                    //TO DO user solves
                }
                else {
                    //program solves
                    sudokuSolver:sudokuSolver(sudoku);
                    cout << sudoku;
                    fms::writeFile(sudoku, userFile);
                }
            }
        }
        else {
            //TO DO generate sudoku
            cout << sudoku;
            //write sudoku base
            fms::writeFile(sudoku, myFile);
            cout << "\n----------------------------------------------------------------------" << endl;
            cout << "Do you want to: \n";
            cout << "\t1. Try solving it\n";
            cout << "\t2. See the solution\n\t:";
            cin >> choice;
            if (choice == 1) {
                //user solves


            }
            else {
                //program solves
                sudokuSolver(sudoku);
                cout << sudoku;
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
            //+1 because the numGame is incremented when a completed Sudoku is written in the file
            cout << "\nRound "<<sudoku.getGameNum() + 1<<"!\n";
        }
    }
    return 0;
}






void assign(Sudoku& s) {    //Arrays are not assignable as a whole in C++. When dealing with arrays, you need to copy their content element-wise or use functions designed to perform array copying.
    int table[9][9] = {
    {9, 0, 0, 0, 2, 0, 0, 0, 3},
    {0, 3, 0, 1, 0, 8, 0, 7, 0},
    {0, 0, 6, 0, 0, 0, 9, 0, 0},
    {0, 9, 0, 0, 4, 0, 0, 3, 0},
    {1, 0, 0, 7, 0, 9, 0, 0, 2},
    {0, 2, 0, 0, 6, 0, 0, 9, 0},
    {0, 0, 5, 0, 0, 0, 8, 0, 0},
    {0, 8, 0, 4, 0, 2, 0, 5, 0},
    {3, 0, 0, 0, 8, 0, 0, 0, 1}
    };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            s.sudokuTable[i][j] = table[i][j];
        }
    }
}

