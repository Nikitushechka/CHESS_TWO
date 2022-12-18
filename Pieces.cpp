#include <iostream>
#include <string>
#include "Pieces.hpp"
using namespace std;


bool Piece::IsAvailable(char new_hor, char new_ver) const = 0;

bool Piece::TryMove(char new_hor, char new_ver, Game* game) {
    if !(this->IsAvailable(new_hor, new_ver)){
        return false;
    }
    if !(this->IsWayClear(new_hor, new_ver)){
        return false;
    }
    if (game->IsCheck()){
        return false;
    }
    if (this->GetType() == "BK"){
        (game->black_king_)->r_castling_available = false;
        (game->black_king_)->l_castling_available = false;
    }
    if (this->GetType() == "WK"){
        (game->white_king_)->r_castling_available = false;
        (game->white_king_)->l_castling_available = false;
    }
    if ((this->GetType() == "BR") && ((this->GetCell)->hor == 0) && ((this->GetCell)->ver == 0)){
        (game->black_king_)->l_castling_available = false;
    }
    if ((this->GetType() == "BR") && ((this->GetCell)->hor == 0) && ((this->GetCell)->ver == 7)){
        (game->black_king_)->r_castling_available = false;
    }
    if ((this->GetType() == "WR") && ((this->GetCell)->hor == 7) && ((this->GetCell)->ver == 0)){
        (game->white_king_)->l_castling_available = false;
    }
    if ((this->GetType() == "WR") && ((this->GetCell)->hor == 7) && ((this->GetCell)->ver == 7)){
        (game->white_king_)->r_castling_available = false;
    }
    if ((this->GetType() == "BP") || (this->GetType() == "WP")){
        ((Pawn*)this)->was_moved = true;
    }
    (this->GetCell).release();
    (game->board_[new_hor][new_ver]).SetPiece(*this);
    this->SetCell(game->board_[new_hor][new_ver]);
    return true;
};

void Piece::SetCell(Cell cell) {
    (this->cell_).reset(cell);
};

unique_ptr<Cell> Piece::GetCell() {
    return cell_;
};

string Piece::GetType() {
    return this->type_;
};

bool Piece::GetColor() {
    return this->color_;
};

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

bool King::IsWayClear(char new_hor, char new_ver) const override {

};

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

bool Queen::IsWayClear(char new_hor, char new_ver) const override {};

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

bool Pawn::IsWayClear(char new_hor, char new_ver) const override {};

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

bool Bishop::IsWayClear(char new_hor, char new_ver) const override {};

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

bool Knight::IsWayClear(char new_hor, char new_ver) const override {};

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

bool Rook::IsWayClear(char new_hor, char new_ver) const override {};
