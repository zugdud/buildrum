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
    WindowManager::getInstance()->switchActiveViewport("fullscreen"); // TODO from config

    mInputEventTypeHandler = new InputEventTypeHandler();
    mInputEventTypeHandler->registerObserver(SDL_QUIT, this);
}

void GameInstance::start()
{
    mMainMenu.configure(ConfigManager::getInstance()->getMenuPropertiesContainer("MainMenu"));
    mMainMenu.resetPosition(WindowManager::getInstance()->getActiveViewport().getRect());

    mRunning = true;

    while ( mRunning )
    {
        mInputEventTypeHandler->pollEventQueue();
    }
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

}
