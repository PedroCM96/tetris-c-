
#ifndef TETRIS_ACTIVEFIGURE_H
#define TETRIS_ACTIVEFIGURE_H


#include "../Figure/Figure.h"

class ActiveFigure {
    public:
        ActiveFigure(int currentX, int currentY, Figure* figure);
        [[nodiscard]] int getCurrentX() const;
        [[nodiscard]] int getCurrentY() const;
        [[nodiscard]] Figure* getFigure() const;
        void updateCoords(int x, int y);

    private:
        int currentX;
        int currentY;
        Figure* figure;
};


#endif //TETRIS_ACTIVEFIGURE_H
