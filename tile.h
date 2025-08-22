#pragma once
enum class TileType
{
    WALL,
    FLOOR
};
struct Tile
{
    TileType type;
    int x,y;
    Tile *up;
    Tile *down;
    Tile *left;
    Tile *right;
    Tile() : type(TileType::WALL), x(0), y(0),
        up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
    Tile(TileType t, int x, int y) : type(t), x(x), y(y),
        up(nullptr), down(nullptr), left(nullptr), right(nullptr) {}
};
