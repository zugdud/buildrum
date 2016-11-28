#include "include/global.hpp"

GameInstance::GameInstance()
{
    mGameInstanceProperties = new GameInstanceProperties();
    mWindowManager = new WindowManager(*mGameInstanceProperties);
}

GameInstance::~GameInstance()
{

}

void GameInstance::init()
{

}
