
#ifndef MIPROYECTO_FIGURE_H
#define MIPROYECTO_FIGURE_H

#include <tuple>


class Figure {
    public:
        explicit Figure(std::tuple<std::tuple<bool, bool, bool>, std::tuple<bool, bool, bool>> structure);
        [[nodiscard]] std::tuple<std::tuple<bool, bool, bool>, std::tuple<bool, bool, bool>> getStructure() const;

    private:
        std::tuple<std::tuple<bool, bool, bool>, std::tuple<bool, bool, bool>> structure;

};


#endif //MIPROYECTO_FIGURE_H
