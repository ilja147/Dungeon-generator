#include "input.h"
#include <iostream>
#include <limits>

GenerationSettings getUserSettings()
{
    GenerationSettings settings;
    std::cout << "Width: ";
    std::cin >> settings.width;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nHeight: ";
    std::cin >> settings.height;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nUse Drunkardwalk?(1 for yes, 0 for no)(its main algorythm): ";
    std::cin >> settings.useDrunkardWalk;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(settings.useDrunkardWalk)
    {
        std::cout << "\nHow many passes to use? ";
        std::cin >> settings.DrunkardWalkSteps;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "\nUse CellularAutomata? (1 for yes, 0 for no): ";
    std::cin >> settings.useCellularAutomata;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\nUse RoomCarving? (1 for yes, 0 for no): ";
    std::cin >> settings.useRoomCarving;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(settings.useRoomCarving)
    {
        std::cout << "\nChoose rooms minimal size: \nX: ";
        std::cin >> settings.RoomMinSizex;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nY: ";
        std::cin >> settings.RoomMinSizey;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nChoose rooms maximal size: \nX: ";
        std::cin >> settings.RoomMaxSizex;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nY: ";
        std::cin >> settings.RoomMaxSizey;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nMinimal number of rooms: ";
        std::cin >> settings.RoomCount;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return settings;
}
