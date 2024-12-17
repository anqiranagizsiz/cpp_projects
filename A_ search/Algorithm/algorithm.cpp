#include <vector>
#include <experimental/random>
#include <vector>
#include "../Globals/globals.h"
#include <cmath>
#include "algorithm.h"
#include "../Objects/board.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <climits>
//  h = abs (current_cell.x – goal.x) + abs (current_cell.y – goal.y)
//  g = steps
//  f = h+g

std::vector<std::vector<int>> directions = {
        {0,-1},
        {0,1},
        {1,0},
        {-1,0}
};
std::vector<Tile*> checkers {};
std::vector<Tile*>& test = checkers;

std::vector<Tile*> get_neighbors(Tile* current_cell)
{
    std::vector<Tile*> neighbors = {}; 
    for(std::vector<int>& direction:directions)
    {
        int new_x = current_cell->x+direction[0];
        int new_y = current_cell->y+direction[1];
        
        if(new_x < grid && new_x>=0 && new_y <grid && new_y>=0){
            int index = new_x + new_y*grid;
            Tile& neighbor = board.elements[index];
            
            if(!neighbor.isobstacle) 
            {
                neighbor.g = current_cell->g+1;
                if(std::find(test.begin(),test.end(),&neighbor)==test.end())
                {
                    neighbors.push_back(&neighbor);
                    neighbor.parent = current_cell;
                }
            }
        }
    }
    test.push_back(current_cell);
    return neighbors;

}
Tile* get_themost_efficient(std::vector<Tile*>& openvector,Tile* end)
{
    Tile* best = nullptr;
    int min_f = INT_MAX;
   for(Tile* tile:openvector)
   {
        if(tile->get_f(end)<min_f)
        {
            best = tile;
            min_f = tile->get_f(end);
        }
   }
    return best;
}
void append_vector(std::vector<Tile*>& openvector,std::vector<Tile*>& closedvector,std::vector<Tile*>& neighbors)
{
    for(Tile* neighbor: neighbors)
    {
        if(std::find(closedvector.begin(),closedvector.end(),neighbor) == closedvector.end())
        {
            if (std::find(openvector.begin(), openvector.end(), neighbor) == openvector.end())
            {
                openvector.push_back(neighbor);
            }
        }

    }
}




void pop_openvector(Tile* best,std::vector<Tile*>& openvector,std::vector<Tile*>& closedvector)
{
    
        
    auto it  = std::find(openvector.begin(),openvector.end(),best);
    openvector.erase(it);        
    
    closedvector.push_back(best);


}

std::vector<Tile*> path(Tile* start, Tile* end)
{
    std::vector<Tile*> openvector;
    std::vector<Tile*> closedvector;
    Tile* current_cell = start;
    current_cell->g = 0;
    int end_c = 0;
    while(current_cell!=end)
    {
        
        int size_prev = openvector.size();
        std::vector<Tile*> neighbors = get_neighbors(current_cell);
        std::cout << "got neighbors" << std::endl;    
        append_vector(openvector,closedvector,neighbors);
        std::cout << "appended vector" << std::endl;
        std::cout << openvector.size() << std::endl;
        current_cell = get_themost_efficient(openvector, end);
        if(current_cell==nullptr)
        {
            std::cout << "no valid path found" << std::endl;
            return {};
        } 
        pop_openvector(current_cell,openvector,closedvector);
        std::cout << "popped the openvector" << std::endl;
        

        
    }
    std::vector<Tile*> path;
    Tile* tilecurrent = end;
    
    while(tilecurrent!=start)
    {
        path.push_back(tilecurrent);
        if(tilecurrent->parent == nullptr)
        {
            std::cerr << "Error: Null parent encountered during path reconstruction." << std::endl;
            return {};
        }
        tilecurrent = tilecurrent->parent;
        
    }
    std::reverse(path.begin(),path.end());
    std::cout<<"Building the path" << std::endl;
    return path;

}


void run(Tile* start,Tile*end)
{
    std::vector<Tile*> pathvec = path(start,end);
    for(Tile* tile:test)
    {
        tile->set_blue();
        board.draw_board(window);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Adjust delay as needed
        
    }
    for(Tile* tile:pathvec)
    {
        tile->set_green();
        board.draw_board(window);
        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1)); // Adjust delay as needed
    }
    test.clear();
}
