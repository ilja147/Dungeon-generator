#include "algorithms.h"
#include <random>
std::random_device rd;
std::mt19937 gen(rd());
void DrunkardWalk(std::vector<std::vector<Tile>> &map)
{
    int width = map.size();
    int height = map[0].size();
    std::uniform_int_distribution <int> dist(1,width-2);
    std::uniform_int_distribution <int> dist2(1,height - 2);
    std::uniform_int_distribution <int> dir(0,3);
    int ax = dist(gen);
    int ay = dist(gen);
    map[ax][ay].type = TileType::FLOOR;
    for (;)
}
