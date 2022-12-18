//
// Created by Jenya on 11.12.2022.
//

#ifndef CHESS_TWO_LOGIC_RAPER_HPP
#define CHESS_TWO_LOGIC_RAPER_HPP

#include <iostream>
#include <string>
#include "Pieces.cpp"
#include "Cell.cpp"



using namespace std;


class Game{
private:
    bool funny_ = true;
    unsigned short move_count_ = 0;
    vector<vector<Cell>> board_;
    King* black_king_;
    King* white_king_;
    vector<Piece*> black_pieces_;
    vector<Piece*> white_pieces_;

    void Init();
    int Play();

public:
    Game();

    void Start();
    void End();
    bool IsFinnished();
};


#endif //CHESS_TWO_LOGIC_RAPER_HPP
