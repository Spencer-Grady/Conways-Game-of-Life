#pragma once
#ifndef GRID_H_
#define GRID_H_

#include <string>
#include <vector>
#include <cstdlib>

#include "cell.h"

class grid {
	// The cells on screen
	// We have a border consisting of inactive cells
	// these sre used in the calculation for the next generation of cells
	// but are not displayed on screen
	cell cells[rowmax + 2][colmax + 2];
public:
	// create a cell at (row, column)
	void create(int row, int column);

	// Draw all the cells
	void draw();

	//populate the grid with cells at random
	void randomize();

	// will the cell at (row, column) survuve to the next generation?
	bool will_survive(int row, int column);

	// will cell be born at (row, colum) in the next generation
	bool will_create(int row, int column);

	// update to next generation
	void update(const grid& next);
};
// non member function
// calculate which cells survuve to the next generation and which are born
void calculate(grid& old_generation, grid& new_generation);

#endif // !GRID_H_
