#include <iostream>
#include <string>
#include <vector>
#include "Cell.hpp"
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
