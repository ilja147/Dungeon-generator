#include "input.h"
#include <iostream>

GenerationSettings getUserSettings()
{
    GenerationSettings settings;
    std::cout << "Width: ";
    std::cin >> settings.width;
    std::cout << "\nHeight: ";
    std::cin >> settings.height;
    std::cout << "\nUse Drinkardwalk?(1 for yes, 0 for no): ";
    std::cin >> settings.DrunkardWalk;
    std::cout << "\nUse CellularAutomata? (1 for yes, 0 for no): ";
    std::cin >> settings.CellularAutomata;
    std::cout << "\nUse RoomCarving? (1 for yes, 0 for no): ";
    std::cin >> settings.RoomCarving;
    return settings;
}
