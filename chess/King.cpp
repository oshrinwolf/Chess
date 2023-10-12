#include "King.h"
#include "Piece.h"
/*
constructor Function
input:x, y, name, isblack
output: none
*/
King::King(int x, int y, char name, bool isBlack) : Piece(y,x,name,isBlack)
{

}

/*
Function checks if move is legel
input: x, y, chess board
output: -1 if ilegal 1 if legal
*/
int King::legal(int x, int y, Piece* board[8][8])
{
	
	if (this->_isBlack)
	{

		int flag = 1;
		if (x == this->_x && y == this->_y)
		{
			flag = -1;
			return flag;
		}
		else if (board[y][x]->blackOrNot() == this->_isBlack)
		{
			flag = -1;
			return flag;
		}
		else if ((abs(y - this->_y) >= 2 || abs(x - this->_x) >= 2))
		{
			flag = -1;
			return flag;
		}
		else if ((abs(y - this->_y) >= 2 && abs(x - this->_x) >= 2))
		{
			flag = -1;
			return flag;
		}


		return flag;
	}
	else
	{
		int flag = 1;
		if (x == this->_x && y == this->_y)
		{
			flag = -1;
			return flag;
		}
		else if (board[y][x]->getName() == '#' && board[y][x]->blackOrNot())
		{
			flag = -1;
			return flag;
		}
		else if (board[y][x]->getName() != '#' && board[y][x]->blackOrNot() == false)
		{
			flag = -1;
			return flag;
		}
		else if ((abs(y - this->_y) >= 2 || abs(x - this->_x) >= 2))
		{
			flag = -1;
			return flag;
		}
		else if ((abs(y - this->_y) >= 2 && abs(x - this->_x) >= 2))
		{
			flag = -1;
			return flag;
		}


		return flag;
	}

}
