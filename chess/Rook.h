#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(int x, int y, char name, bool isBlack);
	virtual int legal(int x, int y, Piece* board[8][8]);
	
};