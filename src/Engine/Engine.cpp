
#include "Engine.h"
#include <iostream>
#include <unistd.h>
#include <curses.h>
#include <termios.h>


Engine::Engine(Board& board, FigureFactory& figureFactory): board(board), figureFactory(figureFactory) {}

void Engine::prepareTerminal() {
    struct termios oldSettings, newSettings;
    tcgetattr(STDIN_FILENO, &oldSettings);

    newSettings = oldSettings;
    newSettings.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

void Engine::start() {
    this->prepareTerminal();
    board.placeFigure(this->figureFactory.getRandomFigure());
    this->update();
}

void Engine::update() {
    std::cout << board.draw() << std::endl;

    while (true) {
        this->handleInput();
        system("clear");
        std::cout << board.draw() << std::endl;
    }
}

void Engine::moveDown() {
    if (!board.canMakeMove(0, 1)) {
        board.placeFigure(this->figureFactory.getRandomFigure());
        return;
    }

    this->moveActiveFigure(0, 1);
}

void Engine::moveRight() {
    if (!board.canMakeMove(1, 0)) {
        return;
    }

    this->moveActiveFigure(1, 0);
}

void Engine::moveLeft() {
    if (!board.canMakeMove(-1, 0)) {
        return;
    }

    this->moveActiveFigure(-1, 0);
}

void Engine::handleInput() {
    int key = getchar();

    if (key == 97) {
        this->moveLeft();
    }

    if (key == 100) {
        this->moveRight();
    }

    if (key == 115) {
        this->moveDown();
    }
}

void Engine::moveActiveFigure(int x, int y) {
    ActiveFigure* activeFigure = board.getActiveFigure();
    Figure figure = *activeFigure->getFigure();
    board.eraseFigure(figure, activeFigure->getCurrentX(), activeFigure->getCurrentY());

    int newX = activeFigure->getCurrentX() + x;
    int newY = activeFigure->getCurrentY() + y;
    board.drawFigure(figure, newX, newY);
    activeFigure->updateCoords(newX, newY);
}

