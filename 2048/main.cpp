#include "Header/globals.hpp"
#include "Header/board.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
int main() {

    window.setFramerateLimit(60);
    Board::initialize();
    Board::move_right();
    while(window.isOpen()) {
        sf::Event event;
        moved_down = false; moved_right= false; moved_left = false; moved_up = false;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }    
            if(event.type == sf::Event::KeyPressed && !Board::is_full()) {
                if(event.key.code == sf::Keyboard::D) {
                    Board::move_right();
                    moved_right ? Board::add_random_cell() : (void) 0 ;
                }
                if(event.key.code == sf::Keyboard::A) {
                    Board::move_left();
                    moved_left ? Board::add_random_cell() : (void) 0 ;
                }
                if(event.key.code == sf::Keyboard::W) {
                    Board::move_up();
                    moved_up ? Board::add_random_cell() : (void) 0 ;
                }
                if(event.key.code == sf::Keyboard::S) {
                    Board::move_down();
                    moved_down ? Board::add_random_cell() : (void) 0;
                }
            }
        }
        window.clear(sf::Color::White);
        Board::_draw();
        if(Board::is_full()){
            Board::game_over();
        }
        //Board::print_info();
        window.display();

   }
}
