#include "Piece.h"
#include "FreePlace.h"

FreePlace::FreePlace(int x, int y, char name) : Piece(y,x,name, false)
{
}

int FreePlace::legal(int x, int y, Piece* board[8][8])
{
	return -1;
}
