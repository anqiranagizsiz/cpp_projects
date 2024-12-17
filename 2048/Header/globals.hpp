#ifndef GLOBALS_HPP
#define GLOBALS_HPP
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
extern int screen_width;
extern int screen_height;
extern sf::RenderWindow window;
extern const std::string window_name;
extern const int tile_length;
extern bool moved_up;
extern bool moved_down;
extern bool moved_right;
extern bool moved_left;
#endif // GLOBALS_HPP
