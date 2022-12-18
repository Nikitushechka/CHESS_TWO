#include <iostream>
#include <string>
#include "Pieces.hpp"
using namespace std;


Piece::Piece(bool color, string type): color_(color), type_(type), cell_(nullptr) {};
Piece::Piece(bool color, string type, Cell& cell): color_(color), type_(type), cell_(make_unique<Cell>(cell)) {};

void Piece::SetCell(Cell& cell) {
    this->cell_ = make_unique<Cell>(cell);
};

unique_ptr<Cell> Piece::GetCell() {
    return cell_;
};

bool Piece::IsAvailable(char new_hor, char new_ver) const = 0;

bool Piece::TryMove(char new_hor, char new_ver) const = 0;

bool King::IsAvailable(char new_hor, char new_ver) const override {
    if !((bool) this->cell_){
        return false;
    }
    char hor = (this->cell_)->hor_;
    char ver = (this->cell_)->ver_;
    if !((1 <= new_hor) && (new_hor <= 8) && (1 <= new_ver) && (new_ver <= 8)){
        return false;
    }
    return ((abs(new_hor - hor) <= 1) && (abs(new_ver - ver) <= 1)) && ((new_hor != hor) || (new_ver != ver));
};

bool King::TryMove(char new_hor, char new_ver) const override {};

bool Queen::IsAvailable(char new_hor, char new_ver) const override {
    if !((bool) this->cell_){
        return false;
    }
    char hor = (this->cell_)->hor_;
    char ver = (this->cell_)->ver_;
    if !((1 <= new_hor) && (new_hor <= 8) && (1 <= new_ver) && (new_ver <= 8)){
        return false;
    }
    return ((abs(new_hor - hor) == abs(new_ver - ver)) || ((new_hor == hor) || (new_ver == ver))) && ((new_hor != hor) || (new_ver != ver));
};

bool Queen::TryMove(char new_hor, char new_ver) const override {};

bool Pawn::IsAvailable(char new_hor, char new_ver) const override {
    if !((bool) this->cell_){
        return false;
    }
    char hor = (this->cell_)->hor_;
    char ver = (this->cell_)->ver_;
    if !((1 <= new_hor) && (new_hor <= 8) && (1 <= new_ver) && (new_ver <= 8)){
        return false;
    }
    return ((new_hor == hor) && ((abs(new_ver - ver) == 1) || (abs(new_ver - ver) == 2))) || ((abs(new_hor - hor) == 1) && (abs(new_ver - ver) == 1));
};

bool Pawn::TryMove(char new_hor, char new_ver) const override {};

bool Bishop::IsAvailable(char new_hor, char new_ver) const override {
    if !((bool) this->cell_){
        return false;
    }
    char hor = (this->cell_)->hor_;
    char ver = (this->cell_)->ver_;
    if !((1 <= new_hor) && (new_hor <= 8) && (1 <= new_ver) && (new_ver <= 8)){
        return false;
    }
    return (abs(new_hor - hor) == abs(new_ver - ver)) && ((new_hor != hor) || (new_ver != ver));
};

bool Bishop::TryMove(char new_hor, char new_ver) const override {};

bool Knight::IsAvailable(char new_hor, char new_ver) const override {
    if !((bool) this->cell_){
        return false;
    }
    char hor = (this->cell_)->hor_;
    char ver = (this->cell_)->ver_;
    if !((1 <= new_hor) && (new_hor <= 8) && (1 <= new_ver) && (new_ver <= 8)){
        return false;
    }
    return abs((new_hor - hor) * (new_ver - ver)) == 2;
};

bool Knight::TryMove(char new_hor, char new_ver) const override {};

bool Rook::IsAvailable(char new_hor, char new_ver) const override {
    if !((bool) this->cell_){
        return false;
    }
    char hor = (this->cell_)->hor_;
    char ver = (this->cell_)->ver_;
    if !((1 <= new_hor) && (new_hor <= 8) && (1 <= new_ver) && (new_ver <= 8)){
        return false;
    }
    return ((new_hor == hor) || (new_ver == ver)) && ((new_hor != hor) || (new_ver != ver));
};

bool Rook::TryMove(char new_hor, char new_ver) const override {};
