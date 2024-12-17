#include "../Header/globals.hpp"
int screen_width = 800;
int screen_height = 800;
const std::string window_name = "2048";
const int tile_length = 200;
sf::RenderWindow window(sf::VideoMode(screen_width,screen_height),window_name);
bool moved_up = false;
bool moved_down = false;
bool moved_right = false;
bool moved_left = false;
