#include "dungeon.h"
#include "algorithms.h"
#include "setting.h"
#include <iostream>
void Dungeon::initializeMap()
{
    map.resize(width, std::vector<Tile>(height));
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            map[x][y].type = TileType::WALL;
            map[x][y].x = x;
            map[x][y].y = y;
        }

    }
}
Dungeon::Dungeon(int w, int h): width(w), height(h) {}
void Dungeon::generate(const GenerationSettings &settings)
{
    initializeMap();
    if(settings.useDrunkardWalk)
    {
        Algorithms::DrunkardWalk(map);
    }
    if(settings.useCellularAutomata)
    {
        Algorithms::CellularAutomata(map);
    }
    if(settings.useRoomCarving)
    {
        Algorithms::RoomCarving(map);
    }
    //estalishNeighbors();
}
void Dungeon::output() const
{
    for(int x = 0; x < width; x++)
    {
        for(int y; y < height; y++)
        {
            std::cout << map[x][y];
        }
        std::cout << "\n";
    }
}
//void save(const std::string &filename) const;
//static Dungeon load(const std::string &filename);
