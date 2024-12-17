#ifndef BOARD_H
#define BOARD_H
#include "tile.h"
#include <vector>
#include <SFML/Graphics.hpp>
class Board
{
    public:
        std::vector<Tile> elements {};


    public:
        Board() = default;
        void fill_board();
        void draw_board(sf::RenderWindow& window);

};







#endif //BOARD_H
