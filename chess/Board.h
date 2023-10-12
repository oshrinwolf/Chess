#pragma once


#include <iostream>
//#include "Piece.h"



#define MAX_X 8
#define MAX_Y 8

class Piece;
class Board
{
protected:
	Piece* _board[8][8];

public:
	Board();
	~Board();
	std::string toString();
	void initBoard();
	int moveInBoard(std::string message);

};

