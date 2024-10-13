#ifndef MAP_H
#define MAP_H



#include <vector>
#include <memory>

#include "square.h"

#include <string>

#include "headers.h"

#pragma once

class Map
{
public:
	Map() {};

	void figureGenerate();
	
	void checkLines();
	
	void lineCrush(int y);

	const Square&& getMap();

	bool checkSquareFill(Coord cord);

private:

	void lowerLines(int y);

	void lowerLine(int y);
	//std::shared_ptr<Square**> map = std::make_shared<Square**>(new Square[10][20]);
	//Square (*map)[20] = new Square[10][20];
	std::shared_ptr<Square> map[10][20];
};

#endif