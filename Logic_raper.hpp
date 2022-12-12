//
// Created by Jenya on 11.12.2022.
//

#ifndef CHESS_TWO_LOGIC_RAPER_HPP
#define CHESS_TWO_LOGIC_RAPER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Pieces.hpp"
#include "Cell.hpp"



using namespace std;


class Game{
private:
    bool funny_ = true;
    unsigned short move_count_ = 0;
    vector<vector<Cell>> board_;

    void init();

public:
    Game();

    int start();
    void end();
    bool is_finnish();
};


#endif //CHESS_TWO_LOGIC_RAPER_HPP
