
#include "Board.h"


Board::Board(int rowsLength, int numberOfRows) {
    for (int i = 0; i <= numberOfRows; i++) {
        Row row(rowsLength);
        this->rows.push_back(row);
    }

    this->xLength = rowsLength;
    this->yLength = numberOfRows;
}

std::vector<Row> Board::getRows() const {
    return this->rows;
}

std::string Board::draw() const {
    std::string board;

    for (const Row& row: this->getRows()) {
        for (Cell* cell: row.getCells()) {
            board += cell->isFilled() ? "⬛" : "⬜";
        }

        board += "\n";
    }

    return board;
}

void Board::placeFigure(Figure* figure) {
    int startX = 0;
    int startY = 0;

    this->drawFigure(*figure, startX, startY);
    this->setActiveFigure(figure, startX, startY);
}

void Board::drawFigure(Figure figure, int x, int y) {
   this->updateFigureCells(figure, x, y);
}

void Board::fillCell(int x, int y) {
    this->getRowAtIndex(y).getCellAtIndex(x)->setFilled(true);
}

Row Board::getRowAtIndex(int index) const {
    return this->rows[index];
}

void Board::eraseFigure(Figure figure, int x, int y) {
    this->updateFigureCells(figure, x, y, true);
}

void Board::emptyCell(int x, int y) {
    this->getRowAtIndex(y).getCellAtIndex(x)->setFilled(false);
}

void Board::updateFigureCells(Figure figure, int x, int y, bool erase) {
    // Top of the figure
    if (std::get<0>(std::get<0>(figure.getStructure()))) {
        erase ? this->emptyCell(x + 0, y + 0) : this->fillCell(x + 0, y + 0);
    }

    if (std::get<1>(std::get<0>(figure.getStructure()))) {
        erase ? this->emptyCell(x + 1, y + 0) : this->fillCell(x + 1, y + 0);
    }

    if (std::get<2>(std::get<0>(figure.getStructure()))) {
        erase ? this->emptyCell(x + 2, y + 0) :  this->fillCell(x + 2, y + 0);
    }

    // Bottom of the figure
    if (std::get<0>(std::get<1>(figure.getStructure()))) {
        erase ? this->emptyCell(x + 0, y + 1) : this->fillCell(x + 0, y + 1);
    }

    if (std::get<1>(std::get<1>(figure.getStructure()))) {
        erase ? this->emptyCell(x + 1, y + 1) : this->fillCell(x + 1, y + 1);
    }

    if (std::get<2>(std::get<1>(figure.getStructure()))) {
        erase ? this->emptyCell(x + 2, y + 1) : this->fillCell(x + 2, y + 1);
    }
}

void Board::setActiveFigure(Figure* figure, int x, int y) {
    auto active = new ActiveFigure(x, y, figure);
    this->activeFigure = active;
}

ActiveFigure *Board::getActiveFigure() const {
    return this->activeFigure;
}

bool Board::canMakeMove(int x, int y) {
    if (!isInsideBoard(x, y)) {
        return false;
    }

    if (isCollision(x, y)) {
        return false;
    }

    return true;
}

bool Board::isCollision(int x, int y) {
    Figure* figure = this->activeFigure->getFigure();
    int newX = this->activeFigure->getCurrentX() + x;
    int newY = this->activeFigure->getCurrentY() + y;

   if (x > 0) {
       bool isTopSideFilled = std::get<2>(std::get<0>(figure->getStructure()));
       bool isBottomSideFilled = std::get<2>(std::get<1>(figure->getStructure()));

       if (isTopSideFilled && this->getRowAtIndex(newY).getCellAtIndex(newX + 2)->isFilled()) {
           return true;
       }

       if (isBottomSideFilled && this->getRowAtIndex(newY + 1).getCellAtIndex(newX + 2)->isFilled()) {
           return true;
       }
   }

   if (x < 0) {
       bool isTopSideFilled = std::get<0>(std::get<0>(figure->getStructure()));
       bool isBottomSideFilled = std::get<0>(std::get<1>(figure->getStructure()));

       if (isTopSideFilled && this->getRowAtIndex(newY).getCellAtIndex(newX)->isFilled()) {
           return true;
       }

       if (isBottomSideFilled && this->getRowAtIndex(newY + 1).getCellAtIndex(newX)->isFilled()) {
           return true;
       }
   }

   if (y > 0) {
       bool isLeftSideFilled = std::get<0>(std::get<1>(figure->getStructure()));
       bool isMidSideFilled = std::get<1>(std::get<1>(figure->getStructure()));
       bool isRightSideFilled = std::get<2>(std::get<1>(figure->getStructure()));

       if (isLeftSideFilled && this->getRowAtIndex(newY + 1).getCellAtIndex(newX)->isFilled()) {
           return true;
       }

       if (isMidSideFilled && this->getRowAtIndex(newY + 1).getCellAtIndex(newX + 1)->isFilled()) {
           return true;
       }

       if (isRightSideFilled && this->getRowAtIndex(newY + 1).getCellAtIndex(newX + 2)->isFilled()) {
           return true;
       }
   }

    return false;

}

bool Board::isInsideBoard(int x, int y) {
    int newX = this->activeFigure->getCurrentX() + x;
    int newY = this->activeFigure->getCurrentY() + y;

    if (newX < 0 || newY < 0) {
        return false;
    }

    if (newX + 2 >= xLength || newY  >= yLength) {
        return false;
    }

    return true;
}

void Board::placeRandomFigure() {

}
