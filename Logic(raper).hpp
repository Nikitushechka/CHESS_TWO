//
// Created by Jenya on 11.12.2022.
//

#ifndef CHESS_TWO_LOGIC_RAPER_HPP
#define CHESS_TWO_LOGIC_RAPER_HPP
#include "Pieces.hpp"
#include "Cell.hpp"
#include <vector>

using namespace std;


class Game{
    bool funny_ = true;
    unsigned short move_count_ = 0;
    vector<vector<Cell>>
public:
    Game();
    void init();
    int start();
    void end();
    bool is_finnish();
};


#endif //CHESS_TWO_LOGIC_RAPER_HPP