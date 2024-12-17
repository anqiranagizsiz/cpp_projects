#include "globals.h"
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
float WIDTH = 1000 ;
float HEIGHT = 1000;
float TILE  = 20;
const float  grid  = WIDTH/TILE;
sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),"A* Search");
Board board;
