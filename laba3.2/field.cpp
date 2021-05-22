#include "field.h"

#include <iostream>

field::field(int x, int y)
{
	this->x = x;
	this->y = y;
	
	matrix = new bool* [x];
	for (int i = 0; i < x; i++)
	{
		matrix[i] = new bool[y];
	}
	
	for (int x1 = 0; x1 < x; x1++) {
		for (int y1 = 0; y1 < y; y1++)
		{
			matrix[x1][y1] = false;
		}
	}	
}

bool field::success_move(position current_position)
{
	if (current_position.get_x() >= x || current_position.get_x() < 0)
		return false;
	if (current_position.get_y() >= y || current_position.get_y() < 0)
		return false;
	if (matrix[current_position.get_x()][current_position.get_y()] == true)
		return false;

	matrix[current_position.get_x()][current_position.get_y()] = true;
	return true;
}

bool field::all_true()
{

	for (int x1 = 0; x1 < x; x1++) {
		for (int y1 = 0; y1 < y; y1++)
		{
			if (matrix[x1][y1] == false)
				return false;
		}
	}
	return true;
}

bool field::print()
{
	std::cout << std::endl;
	for (int x1 = 0; x1 < x; x1++) {

		for (int y1 = 0; y1 < y; y1++)
		{
			char symbol = 'o';
			if (matrix[x1][y1] == true)
				symbol = 'x';
			std::cout << symbol;
		}
		std::cout << std::endl;
	}
	return true;
}

void field::clear_position(position& position)
{
	if (position.get_x() >= x || position.get_x() < 0)
		return;
	if (position.get_y() >= y || position.get_y() < 0)
		return;
	matrix[position.get_x()][position.get_y()] = false;
}
