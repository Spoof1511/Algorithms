#include "eight_queen.h"
#include <iostream>
#include <stdexcept>


void QueenProblem::initialize(const int size)
{
	this->size = size;
	board = new int*[size];

	for (int i = 0; i < size; i++) 
	{
		board[i] = new int[size];
	}

	for (int j = 0; j < size; j++) 
	{
		for (int k = 0; k < size; k++) 
		{
			board[j][k] = 0;
		}
	}

	initialized = true;
	solved = false;
}

bool QueenProblem::isInitialized()
{
	return initialized;
}

bool QueenProblem::isSolved()
{
	return solved;
}

void QueenProblem::backtracking(int queen)
{
	if (initialized == false)
		throw new std::logic_error("Method called before method initialize. Board is not initialized!");

	if (queen == size) 
	{
		numberOfSolutions++;
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		if (isInserted(queen, i))
		{
			board[queen][i] = 1;
			backtracking(queen + 1);
			board[queen][i] = 0;
		}
	}
	solved = true;
	return;
}

bool QueenProblem::isInserted(int queen_row, int queen_col)
{
	int i = 0;
	int j = 1;
	int k = 1;

	while (i < queen_row) 
	{
		if (board[i][queen_col])
		{
			return false;
		}
		i++;
	}

	while ((j <= queen_row)&&(queen_col - j >= 0))
	{
		if (board[queen_row - j][queen_col - j])
		{
			return false;
		}
		j++;
	}

	while ((k <= queen_row)&&(queen_col + k < size))
	{
		if (board[queen_row - k][queen_col + k])
		{
			return false;
		}
		k++;
	}
	return true;
}

long QueenProblem::getNumberOfSolutions()
{
	if (solved == false)
		throw new std::logic_error("Method called before solving the problem!");


	return numberOfSolutions;
}

QueenProblem::~QueenProblem()
{
	if (board != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			delete[] board[i];
		}
		delete[] board;
	}
}

