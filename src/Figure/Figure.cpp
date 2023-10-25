
#include "Figure.h"

Figure::Figure(std::tuple<std::tuple<bool, bool, bool>, std::tuple<bool, bool, bool>> structure) {
    this->structure = structure;
}


std::tuple<std::tuple<bool, bool, bool>, std::tuple<bool, bool, bool>> Figure::getStructure() const {
    return this->structure;
}
