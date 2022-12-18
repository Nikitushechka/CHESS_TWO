#include <memory>
#include "Pieces.cpp"
using namespace std;


class Cell{
    char hor_;
    char ver_;
    unique_ptr<Piece> piece_;
public:
    Cell(char hor, char ver): hor_(hor), ver_(ver), is_empty_(1), piece_(nullptr) {};
    Cell(char hor, char ver, Piece& piece): hor_(hor), ver_(ver), is_empty_(0), piece_(make_unique<Piece>(piece)) {};

    bool IsEmpty() {};
    void SetPiece(Piece& piece) {};
    unique_ptr<Piece> GetPiece() {};
};
