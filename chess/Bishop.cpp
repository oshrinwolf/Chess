#include "Piece.h"
#include "Bishop.h"
/*
constructor Function
input: x, y, name, isbalck
output: none
*/
Bishop::Bishop(int x, int y, char name, bool isBlack) : Piece(y,x,name,isBlack)
{
}

/*
Function checks if move is legel
input: x, y, chess board
output: -1 if ilegal 1 if legal
*/
int Bishop::legal(int x, int y, Piece* board[8][8])
{
	int flag = 1;
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

	if ((this->_x > x || this->_x < x) && this->_y == y)
	{
		flag = -1;
		return flag;
	}

	if ((this->_y > y || this->_y < y) && this->_x == x)
	{
		flag = -1;
		return flag;
	}

	if ((this->_y == y && (this->_x > x || this->_x < x)) || this->_x == x && (this->_y > y || this->_y < y))
	{
		flag = -1;
		return flag;
	}

	if (this->_x < x && this->_y < y)
	{
		for (int x1 = this->_x + 1, y1 = this->_y + 1; x1 < 8 && y1 < 8; x1++, y1++)
		{
			if (x1 == x && y1 == y)
			{
				return 1;
			}
			else if (board[y1][x1]->getName() != '#')
			{
				return -1;
			}
		}
	}
	else if (this->_x > x && this->_y > y)
	{
		for (int x1 = this->_x - 1, y1 = this->_y - 1; x1 >= 0 && y1 >= 0; x1--, y1--)
		{
			if (x1 == x && y1 == y)
			{
	
				return 1;
			}
			else if (board[y1][x1]->getName() != '#')
			{
				return -1;
			}
		}
	}
	else if (this->_x > x && this->_y < y)
	{
		for (int x1 = this->_x - 1, y1 = this->_y + 1; x1 >= 0 && y1 < 8; x1--, y1++)
		{
			if (x1 == x && y1 == y)
			{
				return 1;
			}
			else if (board[y1][x1]->getName() != '#')
			{
				return  -1;
			}
		}
	}
	else if (this->_x < x && this->_y > y)
	{
		for (int x1 = this->_x + 1, y1 = this->_y - 1; x1 < 8 && y1 >= 0; x1++, y1--)
		{
			if (x1 == x && y1 == y)
			{
				return 1;
			}
			else if (board[y1][x1]->getName() != '#')
			{
				return -1;
			}
		}
	}
}
