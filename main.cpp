#include <cstdlib>

#include "input.h"
#include "dungeon.h"
int main()
{

    GenerationSettings settings = getUserSettings();
    Dungeon dungeon(settings.width, settings.height);
    dungeon.generate(settings);
    dungeon.output();
    return 0;
}
