#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
	bool firstStep;
public:
	Pawn(int x, int y, char name, bool isBlack);
	virtual int legal(int x, int y, Piece* board[8][8]);


};