#include <iostream>
#include "Cell.hpp"
using namespace std;

bool Cell::IsEmpty() {
    return !((bool) piece_);
};

void Cell::SetPiece(Piece &piece) {
    this->piece_ = make_shared<Piece>(piece);
};

shared_ptr<Piece> Cell::GetPiece() {
    return piece_;
};
