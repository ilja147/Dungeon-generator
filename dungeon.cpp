#include "dungeon.h"

void Dungeon::initializeMap(int width, int height)
{
    map.resize(width, height);
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
void Dungeon::generate(const GenerationSettings& settings);
{
    initializeMap(width, height);
    if(settings.useDtunkardWalk)
    {
        Algorithms::DrunkardWalk(map);
    }
    if(settings.useCellularAuomata)
    {
        Algorithms::CellularAutomata(map);
    }
    if(settings.useRoomCarving)
    {
        Algorithms::RoomCarving(map);
    }
    estalishNeighbors();
}
void output() const
{
    for(int i = 0; i < )
}
void save(const std::string &filename) const;
static Dungeon load(const std::string &filename);
const std::vector<std::vector<Tile>> &getMap() const{return map;}
int getWidth() const {return width;}
int getHeight() const {return height;}
