#include "Pawn.h"
#include "Board.h"
/*
constructor Function
input:x, y, name. isblck
output: none
*/
Pawn::Pawn(int x, int y, char name, bool isBlack) : Piece(y, x , name, isBlack)
{
	firstStep = true;
}
/*
Function checks if move is legel
input: x, y, chess board
output: -1 if ilegal 1 if legal
*/
int Pawn::legal(int x, int y, Piece* board[8][8])
{

	//-1 = error
	//1 = fine
	if (board[y][x]->getName() != '#')
	{

		if ((x == this->_x) && (y == this->_y))
		{
			return -1;
		}
		else
		{
			if (this->_isBlack == board[y][x]->blackOrNot())
			{
				return -1;
			}
		}
	}

	int flag = 1;

	//std::cout << "legal_y: " << this->_y << ", " << y << std::endl;

	//check if its backwards
	if (this->_isBlack)
	{
		if (this->firstStep)
		{
			if (this->_y - 2 == y && this->_x == x)
			{
				this->firstStep = false;
				flag = 1;
				return flag;
			}
			else if (this->_y - 1 == y && this->_x == x)
			{
				this->firstStep = false;
				flag = 1;
				return flag;
			}
			else if (y >= this->_y)
			{

				flag = -1;
				return flag;
			}
			else if (abs(y - this->_y) > 1)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y - 1 == y && this->_x == x && board[y][x]->getName() != '#')
			{
				flag = -1;
				return flag;
			}
			else if (this->_y - 1 != y && this->_x == x)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y == y && (this->_x > x || this->_x < x || this->_x == x))
			{
				flag = -1;
				return flag;
			}
			else if ((this->_x - 1 == x || this->_x + 1 == x) && this->_y - 1 == y && board[y][x]->getName() == '#')
			{
				flag = -1;
				return flag;
			}
			else if (((this->_x + 1 != x) || (this->_x - 1 != x)) && (this->_y - 1 != y) && (board[y][x]->blackOrNot()))
			{

				flag = -1;
				return flag;

			}
			else
			{
				return 1;
			}

			


		}
		else
		{
			if (y >= this->_y)
			{

				flag = -1;
				return flag;
			}
			else if (abs(y - this->_y) > 1)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y - 1 == y && this->_x == x && board[y][x]->getName() != '#')
			{
				flag = -1;
				return flag;
			}
			else if (this->_y - 1 != y && this->_x == x)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y == y && (this->_x > x || this->_x < x || this->_x == x))
			{
				flag = -1;
				return flag;
			}
			else if ((this->_x - 1 == x || this->_x + 1 == x) && this->_y - 1 == y && board[y][x]->getName() == '#')
			{
				flag = -1;
				return flag;
			}
			else if (((this->_x + 1 != x) || (this->_x - 1 != x)) && (this->_y - 1 != y) && (board[y][x]->blackOrNot()))
			{

				flag = -1;
				return flag;

			}

			return 1;
		}

	}
	else
	{
		if (this->firstStep)
		{
			if (this->_y + 2 == y && this->_x == x)
			{
				this->firstStep = false;
				flag = 1;
				return flag;
			}
			else if (this->_y + 1 == y && this->_x == x)
			{
				this->firstStep = false;
				flag = 1;
				return flag;
			}
			else if (y <= this->_y)
			{

				flag = -1;
				return flag;
			}
			else if (abs(this->_y - y) > 1)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y + 1 == y && this->_x == x && board[y][x]->getName() != '#')
			{
				flag = -1;
				return flag;
			}
			else if (this->_y + 1 != y && this->_x == x)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y == y && (this->_x > x || this->_x < x || this->_x == x))
			{
				flag = -1;
				return flag;
			}
			else if ((this->_x + 1 == x || this->_x - 1 == x) && this->_y + 1 == y && board[y][x]->getName() == '#')
			{
				flag = -1;
				return flag;
			}
			else if (((this->_x + 1 != x) || (this->_x - 1 != x)) && (this->_y + 1 != y) && (!board[y][x]->blackOrNot()))
			{

				flag = -1;
				return flag;

			}
			else
			{
				return 1;
			}




		}
		else
		{
			if (y <= this->_y)
			{

				flag = -1;
				return flag;
			}
			else if (abs(this->_y - y) > 1)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y + 1 == y && this->_x == x && board[y][x]->getName() != '#')
			{
				flag = -1;
				return flag;
			}
			else if (this->_y + 1 != y && this->_x == x)
			{
				flag = -1;
				return flag;
			}
			else if (this->_y == y && (this->_x > x || this->_x < x || this->_x == x))
			{
				flag = -1;
				return flag;
			}
			else if ((this->_x + 1 == x || this->_x - 1 == x) && this->_y + 1 == y && board[y][x]->getName() == '#')
			{
				flag = -1;
				return flag;
			}
			else if (((this->_x + 1 != x) || (this->_x - 1 != x)) && (this->_y + 1 != y) && (!board[y][x]->blackOrNot()))
			{

				flag = -1;
				return flag;

			}

			return 1;
		}
	}

	std::cout << "firststep: " << this->firstStep << std::endl;
	

	
}

