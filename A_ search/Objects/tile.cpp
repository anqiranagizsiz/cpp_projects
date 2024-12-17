#include "tile.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "../Globals/globals.h"

#include <cmath>
Tile::Tile(int par_x, int par_y)
{
    x = par_x;
    y = par_y;
    isobstacle = false;
    isend = false;
    isbeginning = false;
    parent = nullptr;
    g = 0;
    f = 0;
    h = 0;
    
}
void Tile::draw(sf::RenderWindow& window)
{
    sf::RectangleShape tile(sf::Vector2f(TILE,TILE));
    tile.setPosition(x*TILE,y*TILE);
    if(color == "black")
    {
        tile.setFillColor(sf::Color(0,0,0));
    }else if (color == "red")
    {
        tile.setFillColor(sf::Color::Red);
    }else if (color == "green")
    {
        tile.setFillColor(sf::Color::Green);
    }

    else if(color == "blue")
    {
        tile.setFillColor(sf::Color::Blue);
    }
    else{
        tile.setFillColor(sf::Color(255,255,255));
    }
    window.draw(tile);
}

void Tile::turn_obstacle()
{
    isobstacle = true;
    color = "black";
}
void Tile::turn_free()
{
    isobstacle = false;
    color = "white";
}

int Tile::get_f(Tile* end)
{
    h  = abs(x-end->x) + abs(y-end->y);
    f = g+h;
    return f;

    
}

void Tile::set_blue()
{
    color ="blue";
}
void Tile::set_green()
{
    color = "green";
}
