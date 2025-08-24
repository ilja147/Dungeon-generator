#pragma once
struct GenerationSettings
{
    int width;
    int height;
    bool useDrunkardWalk;
    int DrunkardWalkSteps;
    bool useCellularAutomata;
    bool useRoomCarving;
    int RoomMinSizex;
    int RoomMaxSizex;
    int RoomMinSizey;
    int RoomMaxSizey;
    int RoomCount;
};
