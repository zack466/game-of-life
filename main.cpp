#include <iostream>
#include "board.h"

void print_instructions() {
    std::cout
        << "Conway's Game of Life\n"
        << "Press Enter to iterate the game.\n"
        << "Quit with EOF (ctrl-D on Linux, ctrl-Z on Windows).\n"
        << std::endl;
}

int main() {
    print_instructions();

    Board board(10, 20);

    for (int i = 0; i < 5; i++) {
        board.set_alive(i, i);
        board.set_alive(i, i + 1);
    }

    std::string line;
    std::cout << board.to_string(true) << std::endl;
    while (getline(std::cin, line)) {
        board.iterate();
        std::cout << board.to_string(true) << std::endl;
    }
    return 0;
}
