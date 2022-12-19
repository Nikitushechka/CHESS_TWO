#include <memory>
#include "Pieces.hpp"
using namespace std;


class Cell{
    char hor_;
    char ver_;
    unique_ptr<Piece> piece_;
public:
    Cell(): hor_(0), ver_(0), piece_(nullptr) {};
    Cell(char hor, char ver): hor_(hor), ver_(ver), piece_(nullptr) {};
    Cell(char hor, char ver, Piece& piece): hor_(hor), ver_(ver), piece_(make_unique<Piece>(piece)) {};

    bool IsEmpty() {};
    void SetPiece(Piece &piece) {};
    unique_ptr<Piece> GetPiece() {};
};

