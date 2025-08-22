#include "algorithms.h"
#include "tile.h"
#include <random>

void Algorithms::DrunkardWalk(std::vector<std::vector<Tile>> &map, int steps)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    int width = map.size();
    int height = map[0].size();
    std::uniform_int_distribution <int> distx(1,width-2);
    std::uniform_int_distribution <int> disty(1,height - 2);
    std::uniform_int_distribution <int> dir(0,3);
    int ax = distx(gen);
    int ay = disty(gen);
    for(int i = 0; i < steps; i++)
    {
        map[ax][ay].type = TileType::FLOOR;
        int d = dir(gen);
        switch(d)
        {
        case 0:
            if(ay > 0)
                ay--;
            break;
        case 1:
            if(ay < height-1)
                ay++;
            break;
        case 2:
            if(ax > 0)
                ax--;
            break;
        case 3:
            if(ax < width-1)
                ax++;
            break;
        }
    }
}
