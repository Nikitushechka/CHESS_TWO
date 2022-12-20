#include <memory>
#include "Pieces.hpp"
using namespace std;


#ifndef CELL_HPP
#define CELL_HPP

class Cell{
    char hor_;
    char ver_;
    shared_ptr<Piece> piece_;
public:
    Cell(): hor_(0), ver_(0), piece_(nullptr){};
    Cell(char hor, char ver): hor_(hor), ver_(ver), piece_(nullptr){};
    Cell(char hor, char ver, Piece& piece): hor_(hor), ver_(ver) {
        this-> piece_ = make_shared<Piece>(piece);
    };

    bool IsEmpty();
    void SetPiece(Piece &piece);
    shared_ptr<Piece> GetPiece();
};

#endif //CELL_HPP

