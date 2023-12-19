#include "pch.h"
#include "CppUnitTest.h"
#include "../../Sudoku.h" // Include your Sudoku-related headers
#include "../../SudokuSolver.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
    TEST_CLASS(SudokuSolverTests) // Renamed Test class for SudokuSolver
    {
    public:

        // Helper function to compare two Sudoku grids
        bool compareSudokuGrids(const int(&grid1)[9][9], const int(&grid2)[9][9]) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (grid1[i][j] != grid2[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        }

        TEST_METHOD(SolveSolvableSudoku)
        {
            // Create a solvable Sudoku puzzle
            int solvableSudoku[9][9] = {
                // Define your solvable Sudoku puzzle here
            };

            Sudoku& s = Sudoku::getInstance();
            memcpy(s.sudokuTable, solvableSudoku, sizeof(solvableSudoku));

            Assert::IsTrue(sudokuSolver(s)); // Check if the Sudoku puzzle is solvable

            // Define the expected solution for the solvable Sudoku
            int expectedSolution[9][9] = {
                // Define the expected solution here
            };

            Assert::IsTrue(compareSudokuGrids(s.sudokuTable, expectedSolution)); // Compare the solution with expected
        }

        TEST_METHOD(SolveUnsolvableSudoku)
        {
            // Create an unsolvable Sudoku puzzle
            int unsolvableSudoku[9][9] = {
                // Define your unsolvable Sudoku puzzle here
            };

            Sudoku& s = Sudoku::getInstance();
            memcpy(s.sudokuTable, unsolvableSudoku, sizeof(unsolvableSudoku));

            Assert::IsFalse(sudokuSolver(s)); // Check if the Sudoku puzzle is unsolvable
            // Add assertions for unsolvable scenarios
        }

        TEST_METHOD(EmptySudoku)
        {
            // Create an empty Sudoku grid
            int emptySudoku[9][9] = {
                // Define your empty Sudoku puzzle here
            };

            Sudoku& s = Sudoku::getInstance();
            memcpy(s.sudokuTable, emptySudoku, sizeof(emptySudoku));

            Assert::IsTrue(sudokuSolver(s)); // Check if the empty Sudoku puzzle is solvable
            // Add assertions for an empty Sudoku grid
        }

        TEST_METHOD(EdgeCases)
        {
            // Test with extreme cases: completely filled, one empty cell, etc.
            // Add test scenarios for edge cases
        }
    };
}

