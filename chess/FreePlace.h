#pragma once
#include "Piece.h"

class FreePlace : public Piece
{
public:
	FreePlace(int x, int y, char name);
	virtual int legal(int x, int y, Piece* board[8][8]);
};