#include "GenerateSudoku.h"
#include "Sudoku.h"
#include "SudokuSolver.h"
//for using random
#include <cstdlib> 




void generateBaseSudoku(Sudoku& s, int difficulty) {
	s.resetGrid();
	sudokuSolver:sudokuSolver(s);

    int count = 81 - difficulty;
    while (count > 0) {
        int row = rand() % 9; // Generate a random row index (0-8)
        int col = rand() % 9; // Generate a random column index (0-8)

        if (s.sudokuTable[row][col] != 0) {
            s.sudokuTable[row][col] = 0;
            count--;
        }
    }
}