#include "algorithms.h"
#include "tile.h"
#include <random>
#include <vector>

std::tuple<bool,int,int> canPlaceRoom(const std::vector<std::vector<Tile>> &map, const Tile &tile, int roomWidth, int roomHeigh)
{
    int direction = -1;
    bool can = 0;
        if(map[tile.x][tile.y-1].type == TileType::WALL && tile.y > 1)
        {
            direction = 0;
        }
        if(map[tile.x][tile.y+1].type == TileType::WALL && tile.y <= map[0].size()-1)
        {
            direction = 1;
        }
        if(map[tile.x-1][tile.y].type == TileType::WALL && tile.x > 1)
        {
            direction = 2;
        }
        if(map[tile.x+1][tile.y].type == TileType::WALL && tile.x <= map.size()-1)
        {
            direction = 3;
        }
        else
        {
            direction = -1;
        }
    if(direction == -1)
    {
        return {0,0,0};
    }
    if(tile.y + roomHeigh > map.size() || tile.x + roomWidth > map[0].size())
    {
        return {0,0,0};
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution <int> rotationx(0,roomWidth-1);
    std::uniform_int_distribution <int> rotationy(0,roomHeigh-1);
    if(direction == 0)
    {
        int x = rotationx(gen);
        for(int dy = tile.y-1; dy > tile.y-roomHeigh; dy--)
        {
            for(int dx = tile.x; dx < tile.x + roomWidth-x; dx++)
            {
                if(!(map[dy][dx].type == TileType::WALL))
                {
                    return {0,0,0};
                }
            }
        }
        return {1,0,x};
    }
    else if(direction == 1)
    {
        int x = rotationx(gen);
        for(int dy = tile.y+1; dy < tile.y+roomHeigh; dy++)
        {
            for(int dx = tile.x; dx < tile.x + roomWidth-x; dx++)
            {
                if(!(map[dy][dx].type == TileType::WALL))
                {
                    return {0,0,0};
                }
            }
        }
        return {1,1,x};
    }
    else if(direction == 2)
    {
        int y = rotationy(gen);
        for(int dy = tile.y; dy > tile.y+roomHeigh-y;dy--)
        {
            for(int dx = tile.x; dx > tile.x-roomWidth; dx--)
            {
                if(!(map[dy][dx].type == TileType::WALL))
                {
                    return {0,0,0};
                }
            }
        }
        return {1,2,y};
    }
    else if(direction ==3)
    {
        {
            int y = rotationy(gen);
            for(int dy = tile.y; dy < tile.y-roomHeigh+y;dy++)
            {
                for(int dx = tile.x; dx > tile.x+roomWidth; dx++)
                {
                    if(!(map[dy][dx].type == TileType::WALL))
                    {
                        return {0,0,0};
                    }
                }
            }
            return {1,3,y};
        }
    }
    return {can,0,0};
}
void Algorithms::DrunkardWalk(std::vector<std::vector<Tile>> &map, int steps)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    int height = map.size();
    int width = map[0].size();
    std::uniform_int_distribution <int> distx(1,width - 2);
    std::uniform_int_distribution <int> disty(1,height - 2);
    std::uniform_int_distribution <int> dir(0,3);
    int ax = distx(gen);
    int ay = disty(gen);
    map [ay][ax].type = TileType::FLOOR;
    for(int i = 0; i < steps; i++)
    {

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
        map[ay][ax].type = TileType::FLOOR;
    }
}
void Algorithms::CellularAutomata(std::vector<std::vector<Tile>> &map)
{
    std::vector<std::vector<Tile>> map2 = map;
    for(int j = 0; j < map2.size(); j++)
    {
        for(int i = 0; i < map2[0].size(); i++)
        {
            int liveNeighbors = 0;
            for(int dy = -1; dy <= 1; dy++)
            {
                for(int dx = -1; dx <= 1; dx++)
                {
                    if(dx == 0 && dy == 0)
                    {
                        continue;
                    }
                    int nx = i + dx;
                    int ny = j + dy;
                    if(nx < 0 || nx >= map2.size() || ny < 0 || ny >= map2[0].size())
                        liveNeighbors++;
                    else if(map2[ny][nx].type == TileType::WALL)
                        liveNeighbors++;
                }
            }
            if(map2[j][i].type == TileType::WALL)
            {
                if(liveNeighbors >= 5)
                    map2[j][i].type = TileType::WALL;
                else
                    map2[j][i].type = TileType::FLOOR;
            }
            else
            {
                if(liveNeighbors >= 6)
                    map2[j][i].type = TileType::WALL;
                else
                    map2[j][i].type = TileType::FLOOR;
            }
        }
    }
    map = map2;
}
void Algorithms::RoomCarving(std::vector<std::vector<Tile>> &map, int sizex, int sizey, int RoomCount)
{
    std::vector<Tile*> vec;
    for(int j = 0; j < map.size(); j++)
    {
        for(int i = 0; i < map[0].size(); i++)
        {
            if(map[j][i].type == TileType::FLOOR)
            {
                bool hasWallNeighbor = false;
                for(int dy = -1; dy <= 1; dy++)
                {
                    for(int dx = -1; dx <= 1; dx++)
                    {
                        int nx = i+dx;
                        int ny = j+dy;
                        if(nx >= 0 && nx < map[0].size() && ny > 0 && ny < map.size())
                        {
                            if (map[ny][nx].type == TileType::WALL)
                        hasWallNeighbor = true;
                        }
                    }
                }
                if(hasWallNeighbor)
                {

                    vec.push_back(&map[j][i]);
                }
            }
        }
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0,vec.size()-1);

    std::uniform_int_distribution<int> randx(2,sizex);
    std::uniform_int_distribution<int> randy(2,sizey);
    int width = randx(gen);
    int height = randy(gen);
    int count = 0;
    while(count <= RoomCount)
    {
        int random_index = dis(gen);
        auto i = canPlaceRoom(map, *vec[random_index],width, height);
        if(std::get<0>(i)== 1)
        {

            if(std::get<1>(i)==0)
            {
                for(int dy = vec[random_index]->y-1; dy > vec[random_index]->y-height;dy--)
                {
                    for(int dx = vec[random_index]->x; dx < vec[random_index]->x+width-std::get<2>(i); dx++)
                    {
                        map[dy][dx].type = TileType::FLOOR;
                    }
                }
            }
            else if(std::get<1>(i)==1)
            {
                for(int dy = vec[random_index]->y+1; dy < vec[random_index]->y+height;dy++)
                {
                    for(int dx = vec[random_index]->x; dx < vec[random_index]->x+width-std::get<2>(i); dx++)
                    {
                        map[dy][dx].type = TileType::FLOOR;
                    }
                }
            }
            else if(std::get<1>(i)==2)
            {
                for(int dy = vec[random_index]->y; dy > vec[random_index]->y+height-std::get<2>(i);dy--)
                {
                    for(int dx = vec[random_index]->x; dx > vec[random_index]->x-width;dx--)
                    {
                        map[dy][dx].type = TileType::FLOOR;
                    }
                }
            }
            else if(std::get<1>(i)==3)
            {
                for(int dy = vec[random_index]->y; dy > vec[random_index]->y-height+std::get<2>(i);dy--)
                {
                    for(int dx = vec[random_index]->x; dx > vec[random_index]->x+width;dx++)
                    {
                        map[dy][dx].type = TileType::FLOOR;
                    }
                }
            }
            count++;
        }
    }
}
