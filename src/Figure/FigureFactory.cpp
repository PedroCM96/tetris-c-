
#include "FigureFactory.h"
#include "random"
#include "iostream"


Figure FigureFactory::getOrangeRicky() {
    return Figure(std::tuple(std::tuple(false, false, true), std::tuple(true, true, true)));
}

Figure FigureFactory::getBlueRicky() {
    return Figure(std::tuple(std::tuple(true, false, false), std::tuple(true, true, true)));
}

Figure FigureFactory::getHero() {
    return Figure(std::tuple(std::tuple(false, false, false), std::tuple(true, true, true)));
}

Figure FigureFactory::getTeewee() {
    return Figure(std::tuple(std::tuple(false, true, false), std::tuple(true, true, true)));
}

Figure FigureFactory::getSmashboy() {
    return Figure(std::tuple(std::tuple(true, true, false), std::tuple(true, true, false)));
}

Figure FigureFactory::getClevelandZ() {
    return Figure(std::tuple(std::tuple(true, true, false), std::tuple(false, true, true)));
}

Figure FigureFactory::getRhodeIslandZ() {
    return Figure(std::tuple(std::tuple(false, true, true), std::tuple(true, true, false)));
}

Figure* FigureFactory::getRandomFigure() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,6);
    auto randomInteger = uni(rng);

    return &figures[randomInteger];
}

FigureFactory::FigureFactory()
        : figures {
        getOrangeRicky(),
        getBlueRicky(),
        getHero(),
        getTeewee(),
        getSmashboy(),
        getClevelandZ(),
        getRhodeIslandZ()
} {
}

