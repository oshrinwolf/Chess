#pragma once
#include <iostream>
#include "Board.h"

class Piece
{
protected:
	bool _isBlack;
	int _x; 
	int _y;
	char _name;

public:

	Piece() = default;
	Piece(int x, int y, char name, bool isBlack);
	~Piece();
	void setPositionXY(int x, int y);
	virtual int legal(int x, int y, Piece* board[8][8]) = 0;
	char getName();
	
	bool blackOrNot();
	int getX();
	int getY();
};