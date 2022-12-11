//
// Created by Jenya on 11.12.2022.
//
#include "Logic(raper).hpp"
#include <iostream>
#include <string>
//#include <thread>

using namespace std;

Game::Game() {

}

void Game::init() {
    for (int i = 1; i < 9; ++i) {
        for (int j = 1; j < 9; ++j) {
            this->board[i][j] = Cell()
        }
    }
}

int Game::start() {
    this->init();

    while (this->funny_){

        move_count_ += 1;
        cin <<
    }
    return 0;
}

void Game::end() {
    this->funny_ = 0;
}

bool Game::is_finnish() {
    return false;
}


