#include "map.h"



void Map::figureGenerate() {
	Coord dP = {3, 3}; //drawPosition
	map[dP.x][dP.y].get()->fillSquare();
	for (int i = 0;i < 4;) {
		int dirrection = rand() % (10 - 1 + 1) - 1;
		
		switch (dirrection)
		{
		case 1:
			dP = Coord{ 2, 1 };
			break;
		case 2:
			dP = Coord{ 3, 1 };
			break;
		case 3:
			dP = Coord{ 4, 1 };
			break;
		case 4:
			dP = Coord{ 2, 2 };
			break;
		case 5:
			dP = Coord{ 3, 2 };
			break;
		case 6:
			dP = Coord{ 4, 2 };
			break;
		case 7:
			dP = Coord{ 2, 3 };
			break;
		case 8:
			dP = Coord{ 3, 3 };
			break;
		case 9:
			dP = Coord{ 4, 3 };
			break;
		case 10:
			dP = Coord{ 3, 0 };
			break;
		default:
			break;
		}
		
		if (map[dP.x + 1][dP.y].get()->squareIsFill() || map[dP.x - 1][dP.y].get()->squareIsFill()
			|| map[dP.x][dP.y + 1].get()->squareIsFill() || map[dP.x][dP.y - 1].get()->squareIsFill())
		{
			map[dP.x][dP.y].get()->fillSquare();
			i++;
		}

	}
}

void Map::lowerLine(int y) { //private function
	for (int i = 0;i < 10;i++) {
		if (map[i][y].get()->squareIsFill()) {
			map[i][y].get()->unFillSquare();
			map[i][y + 1].get()->fillSquare();
		}
	}
}

void Map::lowerLines(int y) {
	for (int i = 1;i < 20 - y;i++) {
		lowerLine(y - i);
	}
}

void Map::lineCrush(int y) {
	for (int i = 0;i < 10;i++) {
		map[i][y].get()->unFillSquare();
	}
	lowerLines(y);
}

void Map::checkLines() {
	for (int y = 19;y >= 0;y--) {
		int count = 0;
		
		for (int x = 0;x < 10;x++) {
			if (map[x][y].get()->squareIsFill()) {
				count++;
			}
		}
		
		if (count == 10) {
			lineCrush(y);
			y++;
		}

	}
}

const Square&& Map::getMap() {
	return map;
}

bool Map::checkSquareFill(Coord cord) {
	return map[cord.x][cord.y].get()->squareIsFill();
}






