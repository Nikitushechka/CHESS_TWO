#ifndef CELL_HPP_INCLUDED
#define CELL_HPP_INCLUDED
#include <memory>
#include "Pieces.hpp"




class Cell{
    char hor_;
    char ver_;
    bool is_empty_;
    unique_ptr<Piece> piece_;
public:
    Cell(char hor_, char ver_): hor_(hor_), ver_(ver_), is_empty_(1), piece_(nullptr) {}
    Cell(char hor_, char ver_, Piece& piece_): hor_(hor_), ver_(ver_), is_empty_(0), piece_(make_unique<Piece>(piece_)) {}

    bool IsEmpty() {return is_empty_;}
};

#endif // CELL_HPP_INCLUDED
