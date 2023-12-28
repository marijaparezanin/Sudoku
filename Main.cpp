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
    Date: 27.12.2023
    email: marija.parezanin@mensa.ba
    F: FTN SIIT, SV1/2022
*/

#include <iostream>
#include <fstream>


#include "Sudoku.h"
#include "SudokuSolver.h"
#include "FileManagerSudoku.h"
#include "GenerateSudoku.h"
#include "tests/TestRunner.h"

using namespace std;

//Holds the current sudoku
static Sudoku& sudoku = Sudoku::getInstance();

//identical code appears 3 times
//checks sudoku validity and prints gane statistic
void printValid() {
    if (sudoku.validate()) {
        cout << "\n\t\All good!" << endl;
        sudoku.displayStats();
    }
    else {
        cout << "\n\t\tIncorrectly solved" << endl;
        sudoku.displayStats();
    }
}


//since identical code appears twice I've placed it in this function
//reads user solution and compares it to a sudoku solved by my program
void userSolves(string solutionsFilePath, string userSolutionPath) {
    cin.get(); // because it picks up previous enters
    cout << "\n----------------------------------------------------------------------" << endl;
    cout << "Press enter when you're finished writing to file!";
    cin.get();


    readFile(sudoku, userSolutionPath);
    writeFile(sudoku, solutionsFilePath, false);

    if (!sudoku.matchesBaseGrid) {
        cout << "\n\tYour solution doesnt seem to match the base grid provided. \n" << endl;
        //i dont count this as a game played
        return;
    }

    
    printValid();
    sudoku.incPlayedGames();
}


int main(int argc, char* argv[]) {
    //If no files have been passed
    if (argc != 5) {
        std::cerr << "Error: expected 4 file paths via commandline\n\t-user setup\n\t-solutions\n\t-user solution\n\t-display generated" << endl;
        return 0;
    }

    //argv[0] is program name
    string userSetUp = argv[1];
    string allSolutions = argv[2];
    string userSolution = argv[3];
    string viewGenerated = argv[4];  //the file i want to present to user to review generated grid

    cout << "----------------------Welcome to SudokuSphere!----------------------\n";
    int choice = 0;
    while(true){
        try {
            cout << "Do you want to play a:\n";
            cout << "\t1. Pre-made sudoku from file\n";
            cout << "\t2. A new generated sudoku\n\t: ";
            cin >> choice;

            if (choice == 1) {
                //Pre-made sudoku
                sudoku.resetGrid();
                readFile(sudoku, userSetUp); 
                cout << sudoku;
                sudoku.countOriginal();         //since the base sudoku has been set i can count the pre-filled fields
                writeFile(sudoku, allSolutions, false);  //i want every sudoku base and solution written in my solutions file


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
                        userSolves(allSolutions, userSolution);
                    }
                    else {
                        //program solves
                        bool solvable = sudokuSolver(sudoku);
                        cout << sudoku;

                        if (solvable) {
                            printValid();
                        }
                        else {
                            cout << "\nSudoku has an error! Cant be solved.\n";
                        }

                        writeFile(sudoku, allSolutions);
                    }
                }
            }
            else {
                //generate sudoku
                int difficultyChoice;
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "Choose the difficulty level: \n";
                cout << "\t1. Easy (~45 filled cells)\n";
                cout << "\t2. Medium (~40 filled cells)\n";
                cout << "\t3. Hard (~35 filled cells)\n";
                cout << "\t4. Extreme (~20 filled cells)\n";
                cout << "\t5. Insane (~10 filled cells)\n";

                cout << "\t:";
                cin >> difficultyChoice;

                switch (difficultyChoice) {
                case 1:
                    generateBaseSudoku(sudoku, 45);
                    break;
                case 2:
                    generateBaseSudoku(sudoku, 40);
                    break;
                case 3:
                    generateBaseSudoku(sudoku, 35);
                    break;
                case 4:
                    generateBaseSudoku(sudoku, 20);
                    break;
                case 5:
                    generateBaseSudoku(sudoku, 10);
                    break;
                default:
                    std::cout << "Invalid choice";
                    break;
                }

                sudoku.countOriginal();         //since the base sudoku has been set i can count the pre-filled fields


                cout << sudoku;
                //write sudoku base
                writeFile(sudoku, allSolutions, false);
                writeFile(sudoku, viewGenerated, false);



                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "Do you want to: \n";
                cout << "\t1. Try solving it\n";
                cout << "\t2. See the solution\n\t:";
                cin >> choice;

                if (choice == 1) {
                    //user solves
                    userSolves(allSolutions, userSolution);
                }
                else {
                    //program solves
                    sudokuSolver(sudoku);
                    cout << sudoku;

                    printValid();
                    writeFile(sudoku, allSolutions);
                }

            }
            //i want to remove the file i used to let the user see the setup
            remove(viewGenerated.c_str());
            writeEndOfRound(allSolutions, sudoku.getGameNum());

            cout << "\n----------------------------------------------------------------------" << endl;
            cout << "Do you want to keep playing?\n";
            cout << "\t1. Yes!\n";
            cout << "\t2. No, maybe some other time.\n\t: ";
            cin >> choice;

            if (choice == 2) {
                cout << "\nThank you for playing!\n";

                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "Display tests? \n";
                cout << "\t1. Yes!\n";
                cout << "\t2. No.\n\t: ";
                cin >> choice;

                if (choice == 1) {
                    displayTestGenerate();
                    displayTestSolver();
                    displayTestValidate();
                    displayTestFile();
                }

                return 1;
            }
            else {
                cout << "\n----------------------------------------------------------------------" << endl;
                //+1 because the numGame is incremented when a completed Sudoku is written in the file, or called so
                cout << "\nRound " << sudoku.getGameNum() + 1 << "!\n";
            }
        } catch (const std::exception& e) { //an error can occur if the file path is invalid
            std::cerr << "Error occured: " << e.what() << "\n\n";
        }
    }
    return 0;
}
