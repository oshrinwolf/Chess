#include "Piece.h"
/*
constructor Function
input:x, y, name, isblack
output:none
*/
Piece::Piece(int x, int y, char name, bool isBlack)
{
    this->_x = x;
    this-> _y = y;
    this->_name = name;
    this->_isBlack = isBlack;
}
/*
distructor Function
input: none
output: none
*/
Piece::~Piece()
{
    this->_x = 0;
    this->_y = 0;
    this->_name = ' ';
    
}

/*
Function sets position
input:x, y
output:none
*/
void Piece::setPositionXY(int x, int y)
{
    this->_x = x;
    this->_y = y;
}
/*
Function gets the name of the piece
input: none
output: the name
*/
char Piece::getName()
{
    return this->_name;
}

/*
Function checks if current piece is black or not
input: none
output: true or false
*/
bool Piece::blackOrNot()
{
    return this->_isBlack;
}

/*
Function get x
input:none
output:x
*/
int Piece::getX()
{
    return this->_x;
}
/*
Function gets y
input: none
output:y
*/
int Piece::getY()
{
   return this->_y;
}
