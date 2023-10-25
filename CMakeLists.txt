# Especifica la versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.0)

# Define el nombre de tu proyecto
project(Tetris)

# Agrega tus archivos fuente
set(SOURCES
        main.cpp
        src/Board/Board.cpp
        src/Row/Row.cpp
        src/Cell/Cell.cpp
        main.cpp
        src/Figure/Figure.h
        src/Figure/Figure.cpp
        src/Figure/FigureFactory.h
        src/Figure/FigureFactory.cpp
        src/Engine/Engine.h
        src/Engine/Engine.cpp
        src/ActiveFigure/ActiveFigure.h
        src/ActiveFigure/ActiveFigure.cpp
)

# Crea el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})