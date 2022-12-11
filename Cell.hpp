#ifndef CELL_HPP_INCLUDED
#define CELL_HPP_INCLUDED
#include "Pieces.hpp"


class Cell{
    char hor_;
    char ver_;
    bool color_;
    bool is_empty_;
    Piece *piece_;
public:
    Cell(char hor, char ver, bool color);
};

#endif // CELL_HPP_INCLUDED
