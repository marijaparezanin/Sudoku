#pragma once
#include "Sudoku.h"


namespace fms {
	void read_file(Sudoku& s, std::string filePath);

	void write_file(Sudoku& s, std::string filePath);
}