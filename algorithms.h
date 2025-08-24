#pragma once
#include "tile.h"
#include <vector>
namespace Algorithms
{
void DrunkardWalk(std::vector<std::vector<Tile>> &map, int steps);
void CellularAutomata(std::vector<std::vector<Tile>> &map);
void RoomCarving(std::vector<std::vector<Tile>> &map, int sizex, int sizey, int RoomCount);
}

