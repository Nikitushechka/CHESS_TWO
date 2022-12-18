#include <iostream>
#include <string>
#include <memory>
#include "Cell.cpp"
using namespace std;


class Piece{
    bool color_;
    string type_;
    unique_ptr<Cell> cell_;
public:
    Piece(bool color, string type): color_(color), type_(type), cell_(nullptr) {};
    Piece(bool color, string type, Cell& cell): color_(color), type_(type), cell_(make_unique<Cell>(cell)) {};

    virtual bool IsAvailable(char new_hor, char new_ver) const = 0;
    virtual bool IsWayClear(char new_hor, char new_ver) const = 0;
    bool TryMove(char new_hor, char new_ver) {};
    void SetCell(Cell cell) {};
    unique_ptr<Cell> GetCell() {};
    string GetType() {};
    bool GetColor() {};
};

class King: public Piece{
    bool r_castling_available;
    bool l_castling_available;
public:
    King(bool color): r_castling_available(true), l_castling_available(true), Piece(color, color ? "WK" : "BK") {};
    King(bool color, Cell& cell): r_castling_available(true), l_castling_available(true), Piece(color, color ? "WK" : "BK", cell) {};

    bool IsAvailable(char new_hor, char new_ver) const override {};
    bool IsWayClear(char new_hor, char new_ver) const override {};
};

class Queen: public Piece{
public:
    Queen(bool color): Piece(color, color ? "WQ" : "BQ") {};
    Queen(bool color, Cell& cell): Piece(color, color ? "WQ" : "BQ", cell) {};

    bool IsAvailable(char new_hor, char new_ver) const override {};
    bool IsWayClear(char new_hor, char new_ver) const override {};
};

class Pawn: public Piece{
    bool was_moved;
public:
    Pawn(bool color): was_moved(false), Piece(color, color ? "WP" : "BP") {};
    Pawn(bool color, Cell& cell): was_moved(false), Piece(color, color ? "WP" : "BP", cell) {};

    bool IsAvailable(char new_hor, char new_ver) const override {};
    bool IsWayClear(char new_hor, char new_ver) const override {};
};

class Bishop: public Piece{
public:
    Bishop(bool color): Piece(color, color ? "WB" : "BB") {};
    Bishop(bool color, Cell& cell): Piece(color, color ? "WB" : "BB", cell) {};

    bool IsAvailable(char new_hor, char new_ver) const override {};
    bool IsWayClear(char new_hor, char new_ver) const override {};
};

class Knight: public Piece{
public:
    Knight(bool color): Piece(color, color ? "WH" : "BH") {};
    Knight(bool color, Cell& cell): Piece(color, color ? "WH" : "BH", cell) {};

    bool IsAvailable(char new_hor, char new_ver) const override {};
    bool IsWayClear(char new_hor, char new_ver) const override {};
};

class Rook: public Piece{
public:
    Rook(bool color): Piece(color, color ? "WR" : "BR") {};
    Rook(bool color, Cell& cell): Piece(color, color ? "WR" : "BR", cell) {};

    bool IsAvailable(char new_hor, char new_ver) const override {};
    bool IsWayClear(char new_hor, char new_ver) const override {};
};
