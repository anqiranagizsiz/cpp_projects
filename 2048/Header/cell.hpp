#ifndef CELL_HPP
#define CELL_HPP
#include "globals.hpp"
#include "board.hpp"
class Board;
class Cell {
    public:
        int pos_x; 
        int pos_y; // gonna need positions for movement
        int value; // gonna need for addition 
        bool is_occupied; // gonna need for game logic
    public:
        Cell( int px, int py);
        void draw();
        // I know i could have done better i dont give a fuq
        void move_right(std::vector<Cell*>& elements);
        void move_left(std::vector<Cell*>& elements);
        void move_up (std::vector<Cell*>& elements);
        void merge_right(std::vector<Cell*>& elements);
        void move_down(std::vector<Cell*>& elements);
        void liberate(Cell* cell);
        void occupy(Cell* target_cell);
        
};
#endif // CELL_HPP
