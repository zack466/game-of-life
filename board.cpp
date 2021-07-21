#include <iostream>
#include <vector>
#include "board.h"

string Board::toString() {
    string out;
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            if (board[i][j] == 1) {
                out.append("0");
            } else {
                out.append(".");
            }
            out.append(" ");
        }
        out.append("\n");
    }
    return out;
}

Board::Board(size_t h, size_t w) {
    height = h;
    width = w;
    for (size_t i = 0; i < height; i++) {
        vector<int> row;
        for (size_t j = 0; j < height; j++) {
            row.push_back(0);
        }
        board.push_back(row);
    }
}

void Board::setAlive(size_t x, size_t y) {
    if (x >= width || y >= height) {
        throw "Invalid coordinates";
    }
    board[y][x] = 1;
}

void Board::setDead(size_t x, size_t y) {
    if (x >= width || y >= height) {
        throw "Invalid coordinates";
    }
    board[y][x] = 0;
}

void Board::iterate() {
    Board new_board(height, width);
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            if (board[i][j] == 1) {
                size_t neighbors = countNeighbors(j, i);
                if (neighbors < 2 || neighbors > 3) {
                    new_board.board[i][j] = 0;
                } else {
                    new_board.board[i][j] = 1;
                }
            } else {
                size_t neighbors = countNeighbors(j, i);
                if (neighbors == 3) {
                    new_board.board[i][j] = 1;
                }
            }
        }
    }
    board = new_board.board;
}

size_t Board::countNeighbors(size_t x, size_t y) {
    size_t total = 0;
    for (int dx = -1; dx <= 1; dx++ ) {
        for (int dy = -1; dy <= 1; dy++ ) {
            if (dx == 0 && dy == 0) continue;
            if (y + dy >= 0 && y + dy < height) {
                if (x + dx >= 0 && x + dx < width) {
                    if (board[y + dy][x + dx]) {
                        ++total;
                    }
                }
            }
        }
    }
    return total;
}
