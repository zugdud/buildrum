#include "include/global.hpp"

GameInstance::GameInstance()
{

}

GameInstance::~GameInstance()
{

}

bool GameInstance::init()
{
    SDL_Log("GameInstance::init -- BuildProfile: %d \n", G_BUILD_PROFILE);
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

    mInputEventHandler.registerQuitEventObserver(this);

    setupStartScreen();
    return true;
}

void GameInstance::setupStartScreen()
{
    MenuRenderer *menuRenderer = new MenuRenderer();

    menuRenderer->addLayer(MenuManager::Instance().getUIMenu("MainMenu"));
    mInputEventHandler.registerTouchEventObserver(MenuManager::Instance().getUIMenuPtr("MainMenu"));
    WindowManager::getInstance()->setActiveViewContext("start");

    std::vector <Viewport> & startScreenViewports = WindowManager::getInstance()->getActiveViewContext().getViewports();
    for (size_t i = 0; i < startScreenViewports.size(); i++)
    {
        startScreenViewports[i].addRenderer(menuRenderer);
    }
}

void GameInstance::showStartScreen()
{
    mRunning  = true;

    const Window & window = WindowManager::getInstance()->getWindow();
    std::vector <Viewport> & startScreenViewports = WindowManager::getInstance()->getActiveViewContext().getViewports();

    while ( mRunning )
    {
        mInputEventHandler.pollEventQueue();
        window.clearScreen();
        for (size_t i = 0; i < startScreenViewports.size(); i++)
        {
            startScreenViewports[i].renderUpdate();
        }
        window.updateScreen();
    }
}

void GameInstance::quitEventCallback()
{
    mRunning = false;
}
