#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <exception>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector> 
#include "Objects/tile.h"
#include "Objects/board.h"
#include "Globals/globals.h"
#include "Algorithm/algorithm.h"

bool choose_start = false;
bool choose_end = false;
Tile* start;
Tile* end;
bool run_pressed = false;
int main()
{
    window.setFramerateLimit(60);
    board.fill_board();


    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::S)
                {
                    choose_start = true;
                    std::cout << "Choosing start..." << std::endl;
                    
                }
                else if(event.key.code == sf::Keyboard::E)
                {
                    choose_end = true;
                    std::cout << "Choosing end.." << std::endl;
                }

                else if(event.key.code == sf::Keyboard::R)
                {

                    run_pressed = true;
                }
                else if(event.key.code == sf::Keyboard::C)
                {
                    board.elements.clear();
                    board.fill_board();
                    choose_start = false;
                    choose_end = false;
                    start = nullptr;
                    end = nullptr;
                }
                
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(window).x >=0 && sf::Mouse::getPosition(window).x<WIDTH && sf::Mouse::getPosition(window).y>=0 && sf::Mouse::getPosition(window).y < HEIGHT)
            {
                int converted_x = sf::Mouse::getPosition(window).x / TILE;
                int converted_y = sf::Mouse::getPosition(window).y / TILE;
                int index = converted_x + converted_y * grid;

                if(choose_start)
                {
                    board.elements[index].color = "green";
                    board.elements[index].isbeginning = true;
                    start = &board.elements[index];
                    choose_start = false;
                }
                else if(choose_end)
                {
                    board.elements[index].color = "red";
                    board.elements[index].isend = true;
                    end = &board.elements[index];
                    choose_end = false;
                }
                else
                {
                    board.elements[index].turn_obstacle();
                }
            }
            else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)&& sf::Mouse::getPosition(window).x >=0 && sf::Mouse::getPosition(window).x<WIDTH && sf::Mouse::getPosition(window).y>=0 && sf::Mouse::getPosition(window).y < HEIGHT)
            {
                int converted_x = sf::Mouse::getPosition(window).x / TILE;
                int converted_y = sf::Mouse::getPosition(window).y / TILE;
                int index = converted_x + converted_y * grid;
                board.elements[index].turn_free();
            }

            
        }
        window.clear(sf::Color::Black);
        if(run_pressed && start != nullptr && end != nullptr)
        {
            
            run(start,end);
            run_pressed = 0;
            
        }
        board.draw_board(window);
        window.display();
    }
    
    

    return 0;
}
