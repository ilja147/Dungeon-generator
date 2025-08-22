#include "input.h"
#include <iostream>

GenerationSettings getUserSettings()
{
    GenerationSettings settings;
    std::cout << "Width: ";
    std::cin >> settings.width;
    std::cout << "\nHeight: ";
    std::cin >> settings.height;
    std::cout << "\nUse Drinkardwalk?(1 for yes, 0 for no)(its main algorythm): ";
    std::cin >> settings.useDrunkardWalk;
    if(settings.useDrunkardWalk)
    {
        std::cout << "\nHow many passes to use? ";
        std::cin >> settings.DrunkardWalkSteps;
    }
    std::cout << "\nUse CellularAutomata? (1 for yes, 0 for no): ";
    std::cin >> settings.useCellularAutomata;
    std::cout << "\nUse RoomCarving? (1 for yes, 0 for no): ";
    std::cin >> settings.useRoomCarving;
    return settings;
}
