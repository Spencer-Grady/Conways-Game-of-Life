#include "grid.h"

// create a cell at (row, column)
void grid::create(int row, int column) {
	cells[row][column].create();
}

// Draw all the cells, including the border
void grid::draw() {
	// ANSI control command
	// \x1b means "escape"
	// Escape[2J clears the screen and returns the cursor to the home position
	std::cout << "\x1b[2J";
	
	for (int row = 0; row < rowmax; ++row) {
		for (int column = 0; column < colmax; ++column) {
			cells[row][column].draw(row, column);
		}
	}
}

// Populate grid with cells at random
void grid::randomize() {
	const int factor = 5;
	const int cutoff = RAND_MAX / factor;
	time_t now;
	time(&now);
	//srand(now);

	for (int row = 1; row < rowmax; ++row) {
		for (int column = 1; column < colmax; ++column) {
			if (rand() / cutoff == 0) {
				create(row, column);
			}
		}
	}
}

// will the cell at (row, column) survive to next generation
bool grid::will_survive(int row, int column) {
	if (!cells[row][column].isalive()) {
		// there is no cell at this position!
		return false;
	}

	// Find the number of live neighbors for this cell
	//
	// x x x
	// x o x
	// x x x
	int neighbours = cells[row - 1][column - 1].isalive() +
		cells[row - 1][column].isalive() +
		cells[row - 1][column + 1].isalive() +
		cells[row][column - 1].isalive() +
		cells[row][column + 1].isalive() +
		cells[row + 1][column - 1].isalive() +
		cells[row + 1][column].isalive() +
		cells[row + 1][column + 1].isalive();

	if (neighbours < min_neighbours || neighbours > max_neighbours) {
		// cell has died
		return false;
	}

	// if we get here, the cell has survived
	return true;
}

// will a cell be born at (row, column) next generation?
bool grid::will_create(int row, int column) {
	if (cells[row][column].isalive()) {
		// There already is a cell at this position
		return false;
	}
	// Find the number of parents for this cell
	//
	//   x x x
	//   x o x
	//   x x x
	int parents = cells[row - 1][column - 1].isalive() +
		cells[row - 1][column].isalive() +
		cells[row - 1][column + 1].isalive() +
		cells[row][column - 1].isalive() +
		cells[row][column + 1].isalive() +
		cells[row + 1][column - 1].isalive() +
		cells[row + 1][column].isalive() +
		cells[row + 1][column + 1].isalive();

	if (parents < min_parents || parents > max_parents) {
		// Can not create cell here
		return false;
	}

	// If we get here, a new cell can be born
	return true;
}

// Update to next generation
void grid::update(const grid& next) {
	for (int row = 1; row < rowmax; ++row) {
		for (int column = 1; column < colmax; ++column) {
			cells[row][column] = next.cells[row][column];
		}
	}
}

// By default, all cells in the next generation are initially unpopulated
// Calculate which live cells survive to the next generation
// and unpopulated cells are populated in the next generation
void calculate(grid& old_generation, grid& new_generation) {
	for (int row = 1; row < rowmax; ++row) {
		for (int column = 1; column < colmax; ++column) {
			// WIll this cell live or die to next generation?
			if (old_generation.will_survive(row, column)) {
				new_generation.create(row, column);
			}
			// Will this unpopulated cell be populated in the next generation?
			else if (old_generation.will_create(row, column)) {
				new_generation.create(row, column);
			}
		}
	}
}