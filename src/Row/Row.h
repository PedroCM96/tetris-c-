
#ifndef TETRIS_C_PLUS_PLUS_ROW_H
#define TETRIS_C_PLUS_PLUS_ROW_H

#include <vector>
#include "../Cell/Cell.h"

class Row {
    public:
        explicit Row(int length);
        [[nodiscard]] Cell* getCellAtIndex(int index) const;
        [[nodiscard]] std::vector<Cell*> getCells() const;

    private:
        std::vector<Cell*>  cells;
};


#endif //TETRIS_C_PLUS_PLUS_ROW_H
