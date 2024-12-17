#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "../Objects/tile.h"

std::vector<Tile*> get_neighbors(Tile* current_cell,int& g_counter);
Tile* get_themost_efficient(std::vector<Tile*>& neighbors,Tile* end);

void append_vector(std::vector<Tile*>& openvector,std::vector<Tile*>& closedvector,std::vector<Tile*>& neighbors,Tile* end,Tile* current_cell);
Tile* check_openvector(std::vector<Tile*>& openvector,Tile* next_cell,Tile* end);

void pop_openvector(Tile* better,std::vector<Tile*>& openvector,std::vector<Tile*>& closedvector);
void run(Tile* start, Tile* end);
#endif // ALGORITHM_H
