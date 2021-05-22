#include "horse_move.h"



horse_move::horse_move(int x, int y)
{
	this->x = x;
	this->y = y;
}

int horse_move::get_x()
{
	return x;
}

int horse_move::get_y()
{
	return y;
}
