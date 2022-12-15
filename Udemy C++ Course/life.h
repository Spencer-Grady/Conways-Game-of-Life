#pragma once
#ifndef LIFE_H
#define LIFE_H

const char live_cell{ 'X' };
const char dead_cell{ ' ' };

// standard ANSI console, with 1-char border
// occupied rows go from 1-23
// occupied columns go from 1-79

const int rowmax = 23;
const int colmax = 79;

// conway's parameters
const int min_neighbours = 2;
const int max_neighbours = 3;
const int min_parents = 3;
const int max_parents = 3;

#endif // !LIFE_H
