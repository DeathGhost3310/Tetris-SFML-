#ifndef SQUARE_H
#define SQUARE_H


#include "headers.h"

#pragma once
class Square
{
public:

	Square(bool fill = false);
	//Coord m_cord;

	void fillSquare();

	bool squareIsFill();

	void unFillSquare();
//private:
	bool filled = false;
};

#endif