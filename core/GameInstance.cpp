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

    FontManager::getInstance()->configure(ConfigManager::getInstance()->getEnvironmentMediaPropertiesImpl(),
                                          ConfigManager::getInstance()->getFontProfileImpl());

    mInputEventTypeHandler = new InputEventTypeHandler();
    mInputEventTypeHandler->registerObserver(SDL_QUIT, this);
}

void GameInstance::mainMenu()
{
    mMainMenu.configure(ConfigManager::getInstance()->getMenuPropertiesContainer("MainMenu"));
    mMainMenu.resetPosition(WindowManager::getInstance()->getActiveViewport().getRect());

    mRunning  = true;
    MenuRenderer menuRenderer;
    const Window & window = WindowManager::getInstance()->getWindow();
    while ( mRunning )
    {
        mInputEventTypeHandler->pollEventQueue();
        window.clearScreen();

        menuRenderer.renderMenu(mMainMenu);

        window.updateScreen();

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
