
#include "SSteam.h"

int main()
{
    SSteam steam;

    if (steam.FindSteam())
        steam.StartSteam(false);

    std::getchar();
    return 0;
}