#include "dungeon.h"
#include "algorithms.h"
#include "setting.h"
#include <iostream>
void Dungeon::initializeMap()
{
    map.resize(height, std::vector<Tile>(width));
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            map[y][x].type = TileType::WALL;
            map[y][x].x = x;
            map[y][x].y = y;
        }

    }
}
Dungeon::Dungeon(int w, int h): width(w), height(h) {}
void Dungeon::generate(const GenerationSettings &settings)
{
    initializeMap();
    if(settings.useDrunkardWalk)
    {
        Algorithms::DrunkardWalk(map,settings.DrunkardWalkSteps);
    }
    if(settings.useCellularAutomata)
    {
        Algorithms::CellularAutomata(map);
    }
    if(settings.useRoomCarving)
    {
        Algorithms::RoomCarving(map,settings.RoomMinSizex,settings.RoomMinSizey,settings.RoomMaxSizex,settings.RoomMaxSizey,settings.RoomCount);
    }
    //estalishNeighbors();
}
void Dungeon::output() const
{
    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            std::cout << map[y][x];
        }
        std::cout << "\n";
    }
}
//void save(const std::string &filename) const;
//static Dungeon load(const std::string &filename);
