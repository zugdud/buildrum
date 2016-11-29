#include "include/global.hpp"

GameInstance::GameInstance()
{


}

GameInstance::~GameInstance()
{

}

void GameInstance::init()
{
    ConfigManager::getInstance()->loadConstants();
    WindowManager::getInstance()->configure(ConfigManager::getInstance()->getWindowPropertiesImpl());

    mInputEventTypeHandler = new InputEventTypeHandler();
    mInputEventTypeHandler->registerObserver(SDL_QUIT, this);

    mMainMenu = UIMenu(ConfigManager::getInstance()->getMenuPropertiesContainer("MainMenu"));
    SDL_Rect screen = { 100, 100, 1000, 1000 };
    mainMenu.resetPosition(screen);
    mRunning = false;
}

void GameInstance::inputEventTypeCallback(SDL_EventType sdlEventType)
{
    if (sdlEventType == SDL_QUIT)
    {
        mRunning = false;
    }
}

void GameInstance::run()
{
    mRunning = true;

    while ( mRunning )
    {
        mInputEventTypeHandler->pollEventQueue();
    }
}
