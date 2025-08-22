#pragma once
#include <vector>
#include <string>
#include "tile.h"
struct GenerationSettings;
class Dungeon
{
    std::vector<std::vector<Tile>> map;
    int width, height;
public:
    Dungeon(int w, int h);
    void initializeMap();
    void generate(const GenerationSettings& settings);
    void output() const;
    void save(const std::string &filename) const;
    static Dungeon load(const std::string &filename);
    const std::vector<std::vector<Tile>> &getMap() const{return map;}
    int getWidth() const {return width;}
    int getHeight() const {return height;}
};
