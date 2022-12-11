#ifndef PIECES_HPP_INCLUDED
#define PIECES_HPP_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Piece{
    char hor_;
    char ver_;
    bool color_;
    string type_;
public:
    Piece();
    Piece(char hor, char ver, bool color, string type);
    virtual bool check_move(char new_hor, char new_ver);
    void do_move(char new_hor, char new_ver);
};

class King: public Piece{
public:
    King(char hor, char ver, bool color);
    bool check_move(char new_hor, char new_ver) override;
};

class Queen: public Piece{
public:
    Queen(char hor, char ver, bool color);
    bool check_move(char new_hor, char new_ver) override;
};

class Pawn: public Piece{
public:
    Pawn(char hor, char ver, bool color);
    bool check_move(char new_hor, char new_ver) override;
};

class Bishop: public Piece{
public:
    Bishop(char hor, char ver, bool color);
    bool check_move(char new_hor, char new_ver) override;
};

class Knight: public Piece{
public:
    Knight(char hor, char ver, bool color);
    bool check_move(char new_hor, char new_ver) override;
};

class Rook: public Piece{
public:
    Rook(char hor, char ver, bool color);
    bool check_move(char new_hor, char new_ver) override;
};

#endif // PIECES_HPP_INCLUDED
