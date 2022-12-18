#include <iostream>
#include "Cell.hpp"
using namespace std;


Cell::Cell(char hor, char ver): hor_(hor), ver_(ver), is_empty_(1), piece_(nullptr) {};
Cell::Cell(char hor, char ver, Piece& piece): hor_(hor), ver_(ver), is_empty_(0), piece_(make_unique<Piece>(piece)) {};

bool Cell::IsEmpty() {
    return !((bool) piece_);
};

void Cell::SetPiece(Piece piece) {
    (this->piece_).reset(piece);
};

unique_ptr<Piece> Cell::GetPiece() {
    return piece_;
};
