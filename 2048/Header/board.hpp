#ifndef BOARD_HPP
#define BOARD_HPP
#include "globals.hpp"
#include "cell.hpp"
#include <vector>
class Cell;
class Board {
    public:
    static std::vector<Cell*> elements;

    public:
        Board();
        static void _draw();
        static void add_random_cell();
        static void initialize();
        static void print_info();
        static void move_left();
        static void move_right();
        static void move_up();
        static void move_down();
        static bool is_full();
        static void game_over();
};
#endif //BOARD_HPP
