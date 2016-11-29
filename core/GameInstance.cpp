#include "include/global.hpp"

GameInstance::GameInstance()
{

    mWindowManager = new WindowManager(ConfigManager::getInstance()->getGameInstanceProperties());
    mInputEventTypeHandler = new InputEventTypeHandler();

    UIMenu mainMenu = UIMenu(ConfigManager::getInstance()->getMenuPropertiesContainer("MainMenu"));
    SDL_Rect screen = { 100, 100, 1000, 1000 };
    mainMenu.resetPosition(screen);
    mRunning = false;

    const GameInstanceProperties & gameInstanceProperties = ConfigManager::getInstance()->getGameInstanceProperties();
    const std::vector<SDL_EventType> & registeredSDLTypeEvents = gameInstanceProperties.getRegisteredSDLTypeEvents();
    for (size_t i = 0; i < registeredSDLTypeEvents.size(); i++)
    {
        mInputEventTypeHandler->registerObserver(registeredSDLTypeEvents[i], this);
    }
}

GameInstance::~GameInstance()
{

}

void GameInstance::inputEventTypeCallback(SDL_EventType sdlEventType)
{
    if (sdlEventType == SDL_QUIT)
    {
        mRunning = false;
    }
    else if (sdlEventType == SDL_WINDOWEVENT)
    {
        SDL_Log("GameInstance::inputEventTypeCallback -- Window Changed! \n");
    }
    else
    {
        // unhandled / unregistered
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
