#include "Knight.h"
/*
constructor Function
input:x, y, name, isblack
output: none
*/
Knight::Knight(int x, int y, char name, bool isBlack) : Piece(y,x,name,isBlack)
{
}
/*
Function checks if move is legel
input: x, y, chess board
output: -1 if ilegal 1 if legal
*/
int Knight::legal(int x, int y, Piece* board[8][8])
{
	int flag = -1;
	if (board[y][x]->getName() != '#')
	{

		if ((x == this->_x) && (y == this->_y))
		{
			flag = -1;
			return flag;
		}
		else if (this->_isBlack == board[y][x]->blackOrNot())
		{
			flag = -1;
			return flag;
		}

	}

	if ((this->_y == y && (this->_x > x || this->_x < x)) || this->_x == x && (this->_y > y || this->_y < y))
	{
		flag = -1;
		return flag;
	}

	else if (this->_y != y-2 && this->_x != x-2 && !this->_isBlack)
	{
		flag = -1;
		return flag;
	}

	else if (this->_y != y + 2 && this->_x != x + 2 && this->_isBlack)
	{
		flag = -1;
		return flag;
	}

	if ((x == this->_x + 1) && (y == this->_y + 2))
	{
		flag = 1;
	}
	else if ((x == this->_x + 2) && (y == this->_y + 1))
	{
		flag = 1;
	}
	else if ((x == this->_x - 1) && (y == this->_y + 2))
	{
		flag = 1;
	}
	else if ((x== this->_x - 2) && (y == this->_y + 1))
	{
		flag = 1;
	}
	else if ((x == this->_x + 1) && (y == this->_y - 2))
	{
		flag = 1;
	}
	else if ((x== this->_x + 2) && (y == this->_y - 1))
	{
		flag = 1;
	}
	else if ((x == this->_x - 1) && (y == this->_y - 2))
	{
		flag = 1;
	}
	else if ((x == this->_x - 2) && (y == this->_y - 1))
	{
		flag = 1;
	}
	else
	{
		flag = 1;
	}

	return flag;

}
