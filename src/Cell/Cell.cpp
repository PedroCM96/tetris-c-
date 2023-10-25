
#include "Cell.h"

Cell::Cell(bool filled) {
    this->filled = filled;
}

bool Cell::isFilled() const {
    return this->filled;
}

void Cell::setFilled(bool isFilled) {
    this->filled = isFilled;
}
