
#include "Row.h"

Row::Row(int length) {
    for(int i = 0; i < length; i++) {
        auto cell = new Cell(false);
        this->cells.push_back(cell);
    }
}

Cell* Row::getCellAtIndex(int index) const {
    Cell* cell = this->cells[index];
    return cell;
}

std::vector<Cell*> Row::getCells() const {
    return this->cells;
}

