
#ifndef TETRIS_C_PLUS_PLUS_BOARD_H
#define TETRIS_C_PLUS_PLUS_BOARD_H

#include "../Row/Row.h"
#include "../Figure/Figure.h"
#include "../ActiveFigure/ActiveFigure.h"
#include <vector>
#include <string>


class Board {
    public:
        Board(int rowsLength, int numberOfRows);
        [[nodiscard]] std::vector<Row> getRows() const;
        [[nodiscard]] std::string draw() const;
        void placeFigure(Figure* figure);
        void placeRandomFigure();
        void drawFigure(Figure, int x, int y);
        void eraseFigure(Figure, int x, int y);
        [[nodiscard]] ActiveFigure*  getActiveFigure() const;
        bool canMakeMove(int x, int y);

private:
        int xLength;
        int yLength;
        std::vector<Row> rows;
        void fillCell(int x, int y);
        void emptyCell(int x, int y);
        void updateFigureCells(Figure figure, int x, int y, bool erase = false);
        [[nodiscard]] Row getRowAtIndex(int index) const;
        void setActiveFigure(Figure* figure, int x, int y);
        ActiveFigure* activeFigure{};
        bool isCollision(int x, int y);
        bool isInsideBoard(int x, int y);
};

#endif //TETRIS_C_PLUS_PLUS_BOARD_H
