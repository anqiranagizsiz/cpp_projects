#include "board.h"
#include "../Globals/globals.h"
#include <vector>
void Board::fill_board()
{
    for(int y=0;y<grid;++y)
    {
        for(int x=0;x<grid;++x)
        {
            elements.emplace_back(x,y);
        }
    }
}

void Board::draw_board(sf::RenderWindow& window)
{
    for(Tile& tile:elements)
    {
        tile.draw(window);
    }

    for(int x=0;x<grid;++x)
    {
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(x*TILE,0),sf::Color::Black),
            sf::Vertex(sf::Vector2f(x*TILE,HEIGHT),sf::Color::Black)
        };
        window.draw(line,2,sf::Lines);
    }
    for(int y=0;y<grid;++y)
    {
        sf::Vertex line[] = 
        {
            sf::Vertex(sf::Vector2f(0,y*TILE),sf::Color::Black),
            sf::Vertex(sf::Vector2f(WIDTH,y*TILE),sf::Color::Black)
        };
        window.draw(line,2,sf::Lines);

    }
}

