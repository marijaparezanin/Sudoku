#include <iostream>
#include <fstream>


#include "Sudoku.h"
#include "SudokuSolver.h"
#include "FileManagerSudoku.h"

using namespace std;




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



int main(int argc, char* argv[]) {
	Sudoku& sudoku = Sudoku::getInstance();

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
            fms::readFile(sudoku, userFile);
            cout << sudoku;

            if (sudoku.isSolved) {
                //TO DO validate
                //stats
            }
            else {
                cout << "\n----------------------------------------------------------------------" << endl;
                cout << "This sudoku hasnt been solved yet. Do you want to: \n";
                cout << "\t1. Try solving it\n";
                cout << "\t2. See the solution\n\t:";
                cin >> choice;

                if (choice == 1) {
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
            //TO DO generate sudoku in that function i need to calculate how many filled vals there are
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


/*assign(sudoku);
cout << sudoku;

sudokuSolver:sudokuSolver(sudoku);
cout << sudoku;*/