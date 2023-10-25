
#include "ActiveFigure.h"

ActiveFigure::ActiveFigure(int currentX, int currentY, Figure* figure) {
    this->currentX = currentX;
    this->currentY = currentY;
    this->figure = figure;
}

int ActiveFigure::getCurrentX() const {
    return this->currentX;
}

int ActiveFigure::getCurrentY() const {
    return this->currentY;
}

Figure *ActiveFigure::getFigure() const {
    return this->figure;
}

void ActiveFigure::updateCoords(int x, int y) {
    this->currentX = x;
    this->currentY = y;
}



