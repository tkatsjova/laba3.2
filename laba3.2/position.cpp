#include "position.h"

position::position(int x, int y)
{
	this->x = x;
	this->y = y;
}

int position::get_x()
{
	return x;
}

int position::get_y()
{
	return y;
}
