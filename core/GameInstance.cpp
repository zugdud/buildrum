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



    MenuRenderer *menuRenderer = new MenuRenderer();
    menuRenderer->addLayer(MenuManager::Instance().getUIMenu("MainMenu"));
    WindowManager::getInstance()->setActiveViewContext("start");


    const Window & window = WindowManager::getInstance()->getWindow();
    std::vector <Viewport> & viewports = WindowManager::getInstance()->getActiveViewContext().getViewports();
    for (size_t i = 0; i < viewports.size(); i++)
    {
        viewports[i].addRenderer(menuRenderer);
    }

    while ( mRunning )
    {
        mInputEventTypeHandler->pollEventQueue();
        window.clearScreen();
        for (size_t i = 0; i < viewports.size(); i++)
        {
            viewports[i].renderUpdate();
        }

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
