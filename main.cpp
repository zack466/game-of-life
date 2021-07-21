#include <iostream>
#include "board.h"

void print_instructions() {
    std::cout << "Conway's Game of Life\n";
    std::cout << "Press Enter to iterate the game.\n";
    std::cout << "Quit with EOF (ctrl-D on Linux, ctrl-Z on Windows).\n";
}

int main() {
    print_instructions();

    Board board(10, 10);
    for (int i = 0; i < 6; i++) {
        board.setAlive(i, i);
        board.setAlive(i, i + 1);
    }
    std::string line;
    std::cout << board.toString() << std::endl;
    while (getline(std::cin, line)) {
        board.iterate();
        std::cout << board.toString() << std::endl;
    }
    return 0;
}
