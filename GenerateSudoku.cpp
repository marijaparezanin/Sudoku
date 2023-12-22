#include "GenerateSudoku.h"
#include "Sudoku.h"
#include "SudokuSolver.h"
#include <cstdlib> // For rand

// Ensure no submatrices have more than 6 values filled
void ensureSubmatricesLimit(Sudoku& s) {
    int maxFilledInSubmatrix = 6;

    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            int filledInSubmatrix = 0;

            for (int k = i; k < i + 3; ++k) {
                for (int l = j; l < j + 3; ++l) {
                    if (s.sudokuTable[k][l] != 0) {
                        filledInSubmatrix++;
                    }
                }
            }

            while (filledInSubmatrix > maxFilledInSubmatrix) {
                int row = i + rand() % 3;
                int col = j + rand() % 3;

                if (s.sudokuTable[row][col] != 0) {
                    s.sudokuTable[row][col] = 0;
                    filledInSubmatrix--;
                }
            }
        }
    }
}



void generateBaseSudoku(Sudoku& s, int difficulty) {
	s.resetGrid();

	sudokuSolver:sudokuSolver(s);

    int numToDelete = 81 - difficulty;
    while (numToDelete > 0) {
        int row = rand() % 9; // Generate a random row index (0-8)
        int col = rand() % 9; // Generate a random column index (0-8)

        if (s.sudokuTable[row][col] != 0) {
            s.sudokuTable[row][col] = 0;
            numToDelete--;
        }
    }

    ensureSubmatricesLimit(s);
}