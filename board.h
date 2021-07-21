#include <iostream>
#include <vector>

using std::vector;
using std::size_t;
using std::string;

class Board {
public:
    vector<vector<int>> board;
    size_t height, width;

    Board(size_t h, size_t w);

    string toString();

    void setAlive(size_t x, size_t y);
    void setDead(size_t x, size_t y);
    void iterate();
    size_t countNeighbors(size_t x, size_t y);
};
