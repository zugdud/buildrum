#include "include/global.hpp"

int main(int argc, char *args[])
{
    ConfigManager::getInstance()->loadConstants();

    GameInstance gameInstance;
    gameInstance.run();
    return 0;
}
