
#ifndef TETRIS_FIGUREFACTORY_H
#define TETRIS_FIGUREFACTORY_H


#include "Figure.h"

class FigureFactory {
    public:
        FigureFactory();
        [[nodiscard]] Figure* getRandomFigure();


    private:
        Figure figures[7];
        [[nodiscard]] Figure getOrangeRicky();
        [[nodiscard]] Figure getBlueRicky();
        [[nodiscard]] Figure getHero();
        [[nodiscard]] Figure getTeewee();
        [[nodiscard]] Figure getSmashboy();
        [[nodiscard]] Figure getClevelandZ();
        [[nodiscard]] Figure getRhodeIslandZ();
};


#endif //TETRIS_FIGUREFACTORY_H
