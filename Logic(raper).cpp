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
            bool color;
            if ((i + j) % 2 == 0){
                color = 0;
            }
            else{
                color = 1;
            }
            this->board_[i][j] = Cell(i, j, color);
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


