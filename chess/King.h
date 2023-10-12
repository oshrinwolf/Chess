#pragma once
#include "Piece.h"
#include "Pawn.h"
class King : public Piece
{
public:
	King(int x, int y, char name, bool isBlack);
	virtual int legal(int x, int y, Piece* board[8][8]);

};