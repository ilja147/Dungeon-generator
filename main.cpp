#include <cstdlib>
#include <ctime>
#include "input.h"
#include "dungeon.h"
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    GenerationSettings settings = getUserSettings();
    Dungeon dungeon(settings.width, settings.height);
    dungeon.generate(settings);
    dungeon.output();
    return 0;
}
