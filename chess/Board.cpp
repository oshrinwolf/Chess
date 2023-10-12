#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "FreePlace.h"
int thor = 0;
/*
constructor Function, intializes the board
input: none
output: none
*/
Board::Board()
{
	thor = 0;
	this->_board[0][0] = new Rook(0, 0,'R', false); //White Rook
	this->_board[0][7] = new Rook(0, 7, 'R', false); //White Rook
	this->_board[7][7] = new Rook(7, 7, 'r', true); //Black Rook
	this->_board[7][0] = new Rook(7, 0, 'r', true); //Black Rool

	this->_board[0][1] = new Knight(0,1, 'N', false); //White Knight
	this->_board[0][6] = new Knight(0, 6, 'N', false); //White Knight
	this->_board[7][6] = new Knight(7, 6, 'n', true); //Black knight
	this->_board[7][1] = new Knight(7, 1, 'n', true); //Black knight

	this->_board[0][2] = new Bishop(0, 2, 'B', false); //White Bishop
	this->_board[0][5] = new Bishop(0, 5, 'B', false); //White Bishop
	this->_board[7][5] = new Bishop(7, 5, 'b', true); //Black Bishop
	this->_board[7][2] = new Bishop(7, 2, 'b', true); //Black Bishop

	this->_board[0][3] = new King(0, 3, 'K', false); //White King
	this->_board[7][3] = new King(7, 3, 'k', true); //Black King

	this->_board[0][4] = new Queen(0, 4, 'Q', false); //White Queen
	this->_board[7][4] = new Queen(7, 4, 'q', true); //Black Queen 

	for (int i = 0; i < 8; i++)
	{
		this->_board[6][i] = new Pawn(6, i, 'p', true); //Black Pawn
		this->_board[1][i] = new Pawn(1, i, 'P', false); //White Pawn
	}

	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			this->_board[i][j] = new FreePlace(i, j, '#'); //FreePlace
		}
	}
}

/*
distructor Function
input: none
output: none
*/
Board::~Board()
{
	delete[] this->_board;
}

/*
Function prints the current chess board
input: none
output: string
*/
std::string Board::toString()
{
	std::string board = "";
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			board = board + this->_board[i][j]->getName();
			board = board + " ";
		}
		board = board + "\n";
	}
	return board;
}

void Board::initBoard()
{
	
}

/*
Function checks if king if threatend
input: chess board
output: 
*/
int threatend(Piece* board[8][8])
{
	int x = 0;
	int y = 0;
	int count_white = 0;
	int count_black = 0;
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j]->getName() == 'K') //white
			{
				y = i;
				x = j;
			}
		}
	}

	
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j]->getName() != '#' && board[i][j]->blackOrNot() == true && board[i][j]->getName() != 'K')
			{
				int a = board[i][j]->legal(y, x, board);
				if (a != -1)
				{
					count_white++;
				}
			}
		}
	}

	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j]->getName() == 'k') //black
			{
				y = i;
				x = j;
			}
		}
	}

	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j]->getName() != '#' && board[i][j]->blackOrNot() == false  && board[i][j]->getName() != 'k')
			{
				int a = board[i][j]->legal(y, x, board);
				if (a != -1)
				{
					count_black++;
				}
			}
		}
	}

	std::cout << "white threatred: " << count_white << std::endl;
	std::cout << "black threatred: " << count_black << std::endl;
	return 0;
}

/*
Function corrects the order of play
input: the interface message
output: the right flag code
*/
int Board::moveInBoard(std::string message)
{
	std::string positions = message;
	
	threatend(this->_board);
	int xy[2] = {};
	int new_xy[2] = {};

	xy[0] = positions[0] - 'a';
	xy[1] = positions[1] - '1';

	new_xy[0] = positions[2] - 'a';
	new_xy[1] = positions[3] - '1';

	std::cout << "Old positions: " << xy[0] << "    " << xy[1] << std::endl;
	Piece* what_piece = this->_board[xy[1]][xy[0]]; // x = xy[1], y = xy[0]
	int a;
	if (thor == 0 && what_piece->blackOrNot() == false)
	{
		a = what_piece->legal(new_xy[0], new_xy[1], this->_board);
		std::cout << "illegal or not: " << what_piece->legal(new_xy[0], new_xy[1], this->_board) << std::endl;
		if (a != -1)
		{
			thor = 1;
		}
	}
	else if (thor == 1 && what_piece->blackOrNot() == true)
	{
		a = what_piece->legal(new_xy[0], new_xy[1], this->_board);
		std::cout << "illegal or not: " << what_piece->legal(new_xy[0], new_xy[1], this->_board) << std::endl;
		if (a != -1)
		{
			thor = 0;
		}
	}
	else
	{
		return -2;
	}


	if (a != -1)
	{
		this->_board[xy[1]][xy[0]] = new FreePlace(xy[1], xy[0], '#');
		this->_board[new_xy[1]][new_xy[0]] = what_piece;
		what_piece->setPositionXY(new_xy[0], new_xy[1]);
		std::cout << "piece x,y: " << what_piece->getX() << what_piece->getY() << std::endl;
	}




	//what_piece->setPositionXY(xy[1], xy[0]);


	std::cout << this->toString();
	//std::cout << what_piece->getName() << std::endl;

	std::cout << message;
	return a;
}


