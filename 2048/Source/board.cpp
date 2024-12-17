#include "../Header/board.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <ios>
#include <random>
#include <iostream>
#include <chrono>
std::vector<Cell*> Board::elements;

void Board::initialize() {
    for(int y=0;y<screen_height/tile_length;++y) {
        for(int x=0;x<screen_width/tile_length;++x)
        {
            Cell* cell = new Cell(x,y);
            elements.push_back(cell);
        }
    }
    
    elements[0]->is_occupied = true; elements[0]->value = 2;
    elements[1]->is_occupied = true; elements[1]->value = 2;
    elements[2]->is_occupied = true; elements[2]->value = 2;
    elements[3]->is_occupied = true; elements[3]->value = 2;
    /*
        for(int i = 0 ; i<2;i++) {
        // Create a random number generator
        std::random_device rd;  // Seed for the random number generator
        std::mt19937 gen(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> distrib(0, 2); // Range 0 to 2

        // Generate and print a random number between 0 and 2
        int random_x = distrib(gen);
        int random_y = distrib(gen);
        int index = random_x + random_y * (screen_width/tile_length);
        if(!elements[index]->is_occupied) {
            elements[index]->is_occupied = true; 
            elements[index]->value = 2;
        }
    }*/
}
void Board::_draw(){
    for(Cell* cell : elements)
    {
        cell->draw();
    }
    //Draw Lines
    for(int x=0;x<screen_width/tile_length;++x)
    {
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(x*tile_length,0),sf::Color::Black),
            sf::Vertex(sf::Vector2f(x*tile_length,screen_height),sf::Color::Black)
        };
        window.draw(line,2,sf::Lines);
    }
    for(int y=0;y<screen_height/tile_length;++y)
    {
        sf::Vertex line[] = 
        {
            sf::Vertex(sf::Vector2f(0,y*tile_length),sf::Color::Black),
            sf::Vertex(sf::Vector2f(screen_height,y*tile_length),sf::Color::Black)
        };
        window.draw(line,2,sf::Lines);

    }
}

void Board::add_random_cell() {
        std::random_device rd;  // Seed for the random number generator
        std::mt19937 gen(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<> distrib(0, 3); // Range 0 to 2

        // Generate and print a random number between 0 and 2
        int random_x = distrib(gen);
        int random_y = distrib(gen);
        int index = random_x + random_y * (screen_width/tile_length);
        if(!elements[index]->is_occupied) {
            elements[index]->is_occupied = true; 
            elements[index]->value = 2;
        }
        else {
            add_random_cell(); }

}
void Board::print_info() {
    int k = 0;
    for (Cell* cell : elements) {
        // Print cell position and overwrite previous line
        std::cout << "Cell-" << k << " (" << cell->pos_x << ", " << cell->pos_y << ")\n" 
                  << "Value: " << cell->value
                  << " \nOccupied: " << cell->is_occupied <<
                  std::endl;  // Flush the output to update in the same place
        
        k += 1;

        // Optional: Add a delay for visibility
    }
}

void Board::move_right() {
    for ( int i = elements.size() - 1 ; i>=0; i--) {
        if(elements[i]->is_occupied) {
            elements[i]->move_right(elements);
        }
    }
}


void Board::move_left() {
    for ( int i = 0 ; i<elements.size(); i++) {
        if(elements[i]->is_occupied) {
            elements[i]->move_left(elements);
        }
    }
}

void Board::move_up() {
    for ( int x = 0; x<=3 ; x++) {
        for ( int y = 0 ; y<=3 ; y++) {
            int index = x+y*screen_width/tile_length;
            if(elements[index]->is_occupied) {
                elements[index]->move_up(elements);
            }
        }
    }

}

void Board::move_down() {
    for ( int x = 0; x<=3 ; x++) {
        for ( int y = 3 ; y>=0 ; y--) {
            int index = x+y*screen_width/tile_length;
            if(elements[index]->is_occupied) {
                elements[index]->move_down(elements);
            }
        }
    }
}


bool Board::is_full() {
    int i  = 0;
    for(Cell* cell: elements) {
        if(!cell->is_occupied) {
            return false;
        }
        else {
            i+=1;
        }
    }
    if(i == elements.size()) {
        return true;
    }
    else {
        return false;
    }
}

void Board::game_over() {
        sf::Font font;
        font.loadFromFile("Resource/arial/ARIAL.TTF");

        //Configure the text
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(100);
        text.setString("GAME\nOVER!");
        text.setFillColor(sf::Color::Red);
        text.setPosition(screen_width/2-150,screen_height/2-100);
        // Calculate the center position
        if (!font.loadFromFile("Resource/arial/ARIAL.TTF")) {
            // Handle the error if the font file can't be loaded
            std::cerr << "Failed to load font" << std::endl;
        }
        window.draw(text);
}
