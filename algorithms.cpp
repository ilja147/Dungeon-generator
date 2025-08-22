#include "algorithms.h"
#include "tile.h"
#include <random>

void Algorithms::DrunkardWalk(std::vector<std::vector<Tile>> &map, int steps)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    int width = map.size();
    int height = map[0].size();
    std::uniform_int_distribution <int> distx(1,width - 1);
    std::uniform_int_distribution <int> disty(1,height - 1);
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
void Algorithms::CellularAutomata(std::vector<std::vector<Tile>> &map)
{
    std::vector<std::vector<Tile>> map2 = map;
    for(int i = 0; i < map2.size(); i++)
    {
        for(int j = 0; j < map2[0].size(); j++)
        {
            int liveNeighbors = 0;
            for(int dx = -1; dx <= 1; dx++)
            {
                for(int dy = -1; dy <= 1; dy++)
                {
                    if(dx == 0 && dy == 0)
                    {
                        continue;
                    }
                    int nx = i + dx;
                    int ny = j + dy;
                    if(nx < 0 || nx >= map2.size() || ny < 0 || ny >= map2[0].size())
                        liveNeighbors++;
                    else if(map2[nx][ny].type == TileType::WALL)
                        liveNeighbors++;
                }
            }
            if(map2[i][j].type == TileType::WALL)
            {
                if(liveNeighbors >= 4)
                    map2[i][j].type = TileType::WALL;
                else
                    map2[i][j].type = TileType::FLOOR;
            }
            else
            {
                if(liveNeighbors >= 5)
                    map2[i][j].type = TileType::WALL;
                else
                    map2[i][j].type = TileType::FLOOR;
            }
        }
    }
    map = map2;
}
void Algorithms::RoomCarving(std::vector<std::vector<Tile>> &map)
{

}
