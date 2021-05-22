#pragma once
#include "position.h"
class field
{
	int x;
	int y;
	bool** matrix;
public:
	field(int x, int y);
	bool success_move(position current_position);
	bool all_true();

	
	bool print();
	void clear_position(position& position);
};

