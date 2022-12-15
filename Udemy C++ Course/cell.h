#pragma once
#ifndef CELL_H_
#define CELL_H_

#include <iostream>
#include "life.h"

class cell {
	// Cell status
	bool alive;
public:
	// COnstructor
	// cells are empty by default
	cell() : alive(false) {}

	// Draw cell on the grid
	void draw(int row, int col) const;

	// Bring cell to life
	void create() {
		alive = true;
	}

	// End cells life
	void erase() {
		alive = false;
	}

	bool isalive() const { return alive; }
};
#endif // Cell_H_