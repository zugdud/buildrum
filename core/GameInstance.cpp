#include "include/global.hpp"

GameInstance::GameInstance()
{

}

GameInstance::~GameInstance()
{

}

bool GameInstance::init()
{
    // ConfigManager
    ConfigManager::getInstance()->loadConstants();

    // WindowManager
    WindowManager::getInstance()->configure(ConfigManager::getInstance()->getWindowPropertiesImpl());

    // MenuManager
    MenuManager::Instance().configure();

    // FontManager
    if (!FontManager::getInstance()->configure(ConfigManager::getInstance()->getEnvironmentMediaPropertiesImpl(),
                                               ConfigManager::getInstance()->getFontProfileImpl()))
    {
        return false;
    }

    mInputEventTypeHandler = new InputEventTypeHandler();
    mInputEventTypeHandler->registerObserver(SDL_QUIT, this);

    return true;
}

void GameInstance::run()
{
    mRunning  = true;
    MenuRenderer menuRenderer;

    WindowManager::getInstance()->switchActiveViewport("fullscreen");
    MenuManager::Instance().repositionMenu("MainMenu", WindowManager::getInstance()->getActiveViewport().getRect());

    const Window & window = WindowManager::getInstance()->getWindow();
    while ( mRunning )
    {
        mInputEventTypeHandler->pollEventQueue();
        window.clearScreen();
        menuRenderer.renderMenu(MenuManager::Instance().getUIMenu("MainMenu"));
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
