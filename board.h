#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>

class Board {
public:
    std::vector<std::vector<int>> board; // 0 mean dead, 1 means alive
    size_t height, width;

    Board(size_t h, size_t w);

    std::string const to_string();

    void set_alive(size_t x, size_t y);
    void set_dead(size_t x, size_t y);
    void iterate();
    size_t const count_neighbors(size_t x, size_t y);
};

#endif
