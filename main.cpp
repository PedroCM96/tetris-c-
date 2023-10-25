//
// Created by pedro on 25/10/23.
//

#include "src/Board/Board.h"
#include "src/Engine/Engine.h"

int main() {
    auto board = new Board(10, 10);
    auto figureFactory = new FigureFactory();
    auto engine = new Engine(*board, *figureFactory);
    engine->start();
}