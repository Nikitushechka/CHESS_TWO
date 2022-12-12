//
// Created by Jenya on 11.12.2022.
//
#include "Logic_raper.hpp"

using namespace std;

Game::Game() {

}

void Game::init() {

    vector<vector<Cell>> default_board(8);

    default_board[0] = {Cell(1, 1, Rook(0)), Cell(1, 2, Knight(0)), Cell(1, 3, Bishop(0)), Cell(1, 4, Queen(0)),
                        Cell(1, 5, King(0)), Cell(1, 6, Bishop(0)), Cell(1, 7, Knight(0)), Cell(1, 8, Rook(0) )};

    for (int i = 1; i < 9; ++i) default_board[1].push_back(Cell(2, i, Pawn(0)));
    for (int i = 2; i < 6; ++i) {
        for (int j = 1; j < 9; ++j) {
            default_board[i].push_back(Cell(i+1, j));
        }
    }
    for (int i = 1; i < 9; ++i) default_board[6].push_back(Cell(7, i, Pawn(1)));
    default_board[7] = {Cell(8, 1, Rook(1)), Cell(8, 2, Knight(1)), Cell(8, 3, Bishop(1)), Cell(8, 4, Queen(1)),
                        Cell(8, 5, King(1)), Cell(8, 6, Bishop(1)), Cell(8, 7, Knight(1)), Cell(8, 8, Rook(1) )};

    this->board_ = default_board;
    for (vector<Cell>& i: default_board) {
        for (Cell& j: i) {
            if (j.IsEmpty())
        }
    }

    }

int Game::start() {
    this->init();

    while (this->funny_){

        move_count_ += 1;
    }
    return 0;
}

void Game::end() {
    this->funny_ = 0;
}

bool Game::is_finnish() {
    return false;
}


