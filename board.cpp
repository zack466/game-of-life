#include "board.h"

#define TOP_LEFT "\u2554"       // ╔
#define TOP_RIGHT "\u2557"      // ╗
#define BOTTOM_LEFT "\u255A"    // ╚
#define BOTTOM_RIGHT "\u255D"   // ╝
#define VERTICAL "\u2551"       // ║
#define HORIZONTAL "\u2550"     // ═
#define ALIVE "\u25AE"          // ▮
#define DEAD " "                // 

std::string Board::to_string() {
    std::string out;

    // top border
    out.append(TOP_LEFT);
    for (size_t j = 0; j < width * 2 + 1; j++) {
        out.append(HORIZONTAL);
    }
    out.append(TOP_RIGHT);
    out.append("\n");

    for (size_t i = 0; i < height; i++) {
        out.append(VERTICAL); // left border
        out.append(" ");
        for (size_t j = 0; j < width; j++) {
            if (board[i][j] == 1) {
                out.append(ALIVE);
            } else {
                out.append(DEAD);
            }
            out.append(" ");
        }
        out.append(VERTICAL); // right border
        out.append("\n");
    }
    
    // bottom border
    out.append(BOTTOM_LEFT);
    for (size_t j = 0; j < width * 2 + 1; j++) {
        out.append(HORIZONTAL);
    }
    out.append(BOTTOM_RIGHT);

    return out;
}

Board::Board(size_t h, size_t w) {
    height = h;
    width = w;
    for (size_t i = 0; i < height; i++) {
        std::vector<int> row;
        for (size_t j = 0; j < height; j++) {
            row.push_back(0);
        }
        board.push_back(row);
    }
}

void Board::set_alive(size_t x, size_t y) {
    if (x >= width || y >= height) {
        throw "Invalid coordinates";
    }
    board[y][x] = 1;
}

void Board::set_dead(size_t x, size_t y) {
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
                size_t neighbors = count_neighbors(j, i);
                if (neighbors < 2 || neighbors > 3) {
                    new_board.board[i][j] = 0;
                } else {
                    new_board.board[i][j] = 1;
                }
            } else {
                size_t neighbors = count_neighbors(j, i);
                if (neighbors == 3) {
                    new_board.board[i][j] = 1;
                }
            }
        }
    }
    board = new_board.board;
}

size_t Board::count_neighbors(size_t x, size_t y) {
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
