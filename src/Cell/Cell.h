
#ifndef TETRIS_C_PLUS_PLUS_CELL_H
#define TETRIS_C_PLUS_PLUS_CELL_H


class Cell {
    public:
        explicit Cell(bool filled);
        [[nodiscard]] bool isFilled() const;
        void setFilled(bool isFilled);

    private:
        bool filled;
};


#endif //TETRIS_C_PLUS_PLUS_CELL_H
