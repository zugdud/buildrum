#include "include/global.hpp"

int main(int argc, char *args[])
{

    GameInstance gameInstance;

    if (gameInstance.init())
    {
        gameInstance.mainMenu();
    }
    else
    {
        SDL_Log("main -- gameInstance.init error, exiting.");
    }
    return 0;
}
