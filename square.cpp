#include "square.h"

Square::Square(bool fill) : filled(fill) {}

void Square::fillSquare() {
	filled = true;
}

void Square::unFillSquare() {
	filled = false;
}

bool Square::squareIsFill() {
	return filled;
}
