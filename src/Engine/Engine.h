
#ifndef TETRIS_ENGINE_H
#define TETRIS_ENGINE_H


#include "../Board/Board.h"
#include "../Figure/FigureFactory.h"

class Engine {
    public:
        explicit Engine(Board& board, FigureFactory& figureFactory);
        void start();
        void update();
        void moveDown();
        void moveRight();
        void moveLeft();
    private:
        Board& board;
        FigureFactory& figureFactory;
        void prepareTerminal();
        void handleInput();
        void moveActiveFigure(int x, int y);
};


#endif //TETRIS_ENGINE_H
