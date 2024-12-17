#ifndef  TILE_H
#define  TILE_H
#include <SFML/Graphics.hpp>

class Tile
{
    public:
        int x;
        int y;
        std::string color = "white";
        bool isobstacle;
        bool isend;
        bool isbeginning;
        int g;
        int f;
        int h;
        Tile* parent;
    public:
        Tile(int par_x, int par_y);
        void draw(sf::RenderWindow& window);
        void turn_obstacle();
        void turn_free();
        void draw_path(sf::RenderWindow& window);
        int get_f(Tile* end);
        void set_blue();
        void set_green();
        
        
        
};

#endif // TILE_H
