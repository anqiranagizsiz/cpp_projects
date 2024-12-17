#include "../Header/cell.hpp"
#include "../Header/globals.hpp"
#include <iostream>

Cell::Cell(int px, int py) {
    pos_x = px;
    pos_y = py;
    value = 0;
    is_occupied = false;

}

void Cell::draw() {
    if(is_occupied) {

        sf::RectangleShape tile;
        tile.setSize(sf::Vector2f(tile_length,tile_length));
        switch (value) {
            case 2:
                tile.setFillColor(sf::Color(128,128,128));
                break;
            case 4:
                tile.setFillColor(sf::Color(229, 216, 186));
                break;
            case 8:
                tile.setFillColor(sf::Color(226, 178, 127));
                break;
            case 16:
                tile.setFillColor(sf::Color(221, 127, 99));
                break;
            case 32:
                tile.setFillColor(sf::Color(220, 110, 79));
                break;
            default:
            if (value >= 64) {
                tile.setFillColor(sf::Color(220, 110, 79));
            }
            break;
        }
        //Set font
        sf::Font font;
        font.loadFromFile("Resource/arial/ARIAL.TTF");

        //Configure the text
        sf::Text text;
        text.setFont(font);
        text.setString(std::to_string(value));
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::Black);
        text.setPosition(sf::Vector2f((pos_x+0.45)*tile_length,(pos_y+0.45)*tile_length));

        if (!font.loadFromFile("Resource/arial/ARIAL.TTF")) {
            // Handle the error if the font file can't be loaded
            std::cerr << "Failed to load font" << std::endl;
        }
        tile.setPosition(sf::Vector2f(pos_x*tile_length,pos_y*tile_length));
        window.draw(tile);
        window.draw(text);
    }
}


void Cell::move_right(std::vector<Cell*>& elements) {
    // Find right-most empty cell
    int current_index = pos_x+pos_y*screen_width/tile_length;
    int px = pos_x; // To prevent segmentation error
    for (int i = 3; i >= pos_x+1 ; i--) {
    int target_index = i + pos_y*screen_width/tile_length;
        if(!elements[target_index]->is_occupied) {
            occupy(elements[target_index]);
            liberate(elements[pos_x+pos_y*screen_width/tile_length]);
            current_index = target_index;
            px = i;
            moved_right = true;
            break;

        }
    }
    if(px+1<=3  /*&& elements[current_index]->value != 0*/ && elements[current_index]->value == elements[current_index+1]->value) {
        elements[current_index]->occupy(elements[current_index+1]);
        liberate(elements[current_index]);
        moved_right = true;
    }
} 



void Cell::move_left(std::vector<Cell*>& elements) {
    // Find left-most empty cell
    int px = pos_x;
    int current_index = pos_x+pos_y*screen_width/tile_length;
    for (int i = 0; i <= pos_x-1 ; i++) {
    int target_index = i + pos_y*screen_width/tile_length;
        if(!elements[target_index]->is_occupied) {
            occupy(elements[target_index]);
            liberate(elements[pos_x+pos_y*screen_width/tile_length]);
            current_index = target_index;
            px = i;
            moved_left = true;
            break;
        }
    }
    if (px - 1 >= 0 && elements[current_index]->value == elements[current_index-1]->value) {
        elements[current_index-1]->occupy(elements[current_index-1]);
        liberate(elements[current_index]);
        moved_left = true;
    }
}

void Cell::move_up(std::vector<Cell*>& elements) {
    int py = pos_y;
    int current_index = pos_x + pos_y*screen_width/tile_length;
    for (int y = 0; y<pos_y  ; y++) {
        int target_index  = pos_x + y*screen_width/tile_length; 
        if(!elements[target_index]->is_occupied){
            occupy(elements[target_index]);
            liberate(elements[pos_x+pos_y*screen_width/tile_length]);
            current_index  = target_index;
            py = y;
            moved_up = true;
            break;
        }
    }

    
    if(py-1>=0 && elements[current_index]->value == elements[current_index-4]->value )
    {
        elements[current_index]->occupy(elements[current_index-4]);
        liberate(elements[current_index]);
        moved_up = true;
    }

}

void Cell::move_down(std::vector<Cell*>& elements) {
    int py = pos_y;
    int current_index = pos_x + pos_y*screen_width / tile_length;
    for (int y = 3; y>=pos_y+1; y--) {
        int target_index = pos_x + y*screen_width/tile_length;
        if(!elements[target_index]->is_occupied) {
            occupy(elements[target_index]);
            liberate(elements[pos_x+pos_y*screen_width/tile_length]);
            current_index = target_index;
            py = y;
            moved_down = true;
            break;
        }
    }

    if ( py+1 <= 3 && elements[current_index]->value == elements[current_index+4]->value) {
        elements[current_index]->occupy(elements[current_index+4]);
        liberate(elements[current_index]);
        moved_down = true;
    }
}
void Cell::liberate(Cell* cell) {
    cell->value = 0;
    cell->is_occupied = false;
}

void Cell::occupy(Cell* target_cell) {
    target_cell->value += value;
    target_cell->is_occupied =  true;
}
