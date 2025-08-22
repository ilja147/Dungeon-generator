#ifndef DUNGEON_H
#define DUNGEON_H
#include <vector>
#include <string>
class Dungeon
{
    std::vector<std::vector<Tile>> map;
    int width, height;
    void applyDrunkardWalk();
    void applyCellularAutomata();
    void applyRoomCarving();
    void establishNeighbors();
public:
    Dungeon(int w, int h);
    void generate(const GenerationSettings& settings);
    void output() const;
    void save(const std::string &filename) const;
    static Dungeon load(const std::string &filename);
    const std::vector<std::vector<Tile>> &getMap() const{return map;}
    int getWidth() const {return width;}
    int getHeight() const {return height};
};

#endif // DUNGEON_H
