#include "Piece.h"
#include "Rook.h"

Rook::Rook(int x, int y, char name, bool isBlack) : Piece(y,x,name,isBlack)
{
}


/*
Function checks if move is legel
input: x, y, chess board
output: -1 if ilegal 1 if legal
*/
int Rook::legal(int x, int y, Piece* board[8][8])
{
	//legal = 1
	//illegal = -1
	int flag = 1;
	if (board[this->_y][this->_x]->getName() == '#')
	{
		flag = 1;
		return flag;
	}

	else if (this->_x == x && this->_y == y)
	{
		flag = -1;
		return flag;
	}

	else if ((board[y][x]->getName() != '#') && (this->_isBlack == board[y][x]->blackOrNot()))
	{
		flag = -1;
		return flag;
	}

	else if (this->_y != y && this->_x != x)
	{
		flag = -1;
		return flag;
	}

	flag = 1;
	if (this->_y == y)
	{
		if (x < this->_x)
		{
			for (int i = this->_x + 2; i < x; i++)
			{
				if (board[this->_x][i]->getName() != '#')
				{
					flag = -1;
					return flag;
				}
			}
		}
		else
		{
			for (int i = this->_y - 2; i > x; i--)
			{
				if ((board[this->_y][i]->getName() != '#'))
				{
					flag = -1;
					return flag;
				}
			}
		}
	}
	if (x == this->_x)
	{
		if (y < this->_y)
		{
			for (int y1 = this->_y - 1; y1 >= 0; y1--)
			{
				if (y1 == y)
				{
					return 1;
				}
				else if (board[y1][x]->getName() != '#')
				{
					return -1;
				}
			}
		}
		else if (y > this->_y)
		{
			for (int y1 = this->_y + 1; y1 < 8; y1++)
			{
				if (y1 == y)
				{
					return 1;
				}
				else if (board[y1][x]->getName() != '#')
				{
					return -1;
				}
			}
		}
	}
	else if (y == this->_y)
	{
		if (x < this->_x)
		{
			for (int x1 = this->_x - 1; x1 >= 0; x1--)
			{
				if (x1 == x)
				{
					return 1;
				}
				else if (board[y][x1]->getName() != '#')
				{
					return -1;
				}
			}
		}
		else if (x > this->_x)
		{
			for (int x1 = this->_x + 1; x1 < 8; x1++)
			{
				if (x1 == x)
				{
					return 1;
				}
				else if (board[y][x1]->getName() != '#')
				{
					return -1;
				}
			}
		}
	}
	return flag;
}
