#include <iostream>
#include <string>
#include "Pieces.hpp"
using namespace std;


Piece::Piece(char hor, char ver, bool color, string type): hor_(hor), ver_(ver), color_(color), type_(type) {};

bool Piece::check_move(char new_hor, char new_ver){};

void Piece:: do_move(char new_hor, char new_ver){
    this->hor_ = new_hor;
    this->ver_ = new_ver;
};

King::King(char hor, char ver, bool color): Piece(hor, ver, color, color ? "WK" : "BK") {};

bool King::check_move(char new_hor, char new_ver){};

Queen::Queen(char hor, char ver, bool color): Piece(hor, ver, color, color ? "WQ" : "BQ") {};

bool Queen::check_move(char new_hor, char new_ver){};

Pawn::Pawn(char hor, char ver, bool color): Piece(hor, ver, color, color ? "WP" : "BP") {};

bool Pawn::check_move(char new_hor, char new_ver){};

Bishop::Bishop(char hor, char ver, bool color): Piece(hor, ver, color, color ? "WB" : "BB") {};

bool Bishop::check_move(char new_hor, char new_ver){};

Knight::Knight(char hor, char ver, bool color): Piece(hor, ver, color, color ? "WH" : "BH") {};

bool Knight::check_move(char new_hor, char new_ver){};

Rook::Rook(char hor, char ver, bool color): Piece(hor, ver, color, color ? "WR" : "BR") {};

bool Rook::check_move(char new_hor, char new_ver){};
