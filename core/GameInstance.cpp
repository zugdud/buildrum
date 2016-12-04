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

    // Audio Manager
    if (!AudioManager::Instance().configure(ConfigManager::getInstance()->getEnvironmentMediaPropertiesImpl(),
                                            ConfigManager::getInstance()->getAudioContentImpl()))
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

    // register input handlers with menu
    std::vector<UIGridCell> & uiGridCells = MenuManager::Instance().getUIMenu("MainMenu")->getGridCells();
    for (size_t i = 0; i < uiGridCells.size(); i++)
    {
        mInputEventHandler.registerPointEventObserver(uiGridCells[i].getUIButton());
    }

    // add menu as a layer to fullscreen renderer
    menuRenderer->addLayer(MenuManager::Instance().getUIMenu("MainMenu"));

    // add renderers to viewport
    WindowManager::getInstance()->setActiveViewContext("MainMenu");
    std::vector <Viewport> & startScreenViewports = WindowManager::getInstance()->getActiveViewContext().getViewports();
    for (size_t i = 0; i < startScreenViewports.size(); i++)
    {
        startScreenViewports[i].addRenderer(menuRenderer);
    }
}

void GameInstance::setupGameScene()
{
    // todo
}


void GameInstance::showStartScreen()
{
    WindowManager::getInstance()->setActiveViewContext("MainMenu");
    mRunning  = true;

    const Window & window = WindowManager::getInstance()->getWindow();
    std::vector <Viewport> & startScreenViewports = WindowManager::getInstance()->getActiveViewContext().getViewports();

    // play music
    AudioManager::Instance().setMusicTrack("MainMenu");
    AudioManager::Instance().playMusic();
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
    AudioManager::Instance().stopMusic();
}

void GameInstance::showGameScene()
{
    WindowManager::getInstance()->setActiveViewContext("GameScene");
    mRunning  = true;

    const Window & window = WindowManager::getInstance()->getWindow();
    std::vector <Viewport> & gameSceneViewports = WindowManager::getInstance()->getActiveViewContext().getViewports();

    // play music
    AudioManager::Instance().setMusicTrack("GameScene1");
    AudioManager::Instance().playMusic();
    while ( mRunning )
    {
        mInputEventHandler.pollEventQueue();
        window.clearScreen();
        for (size_t i = 0; i < gameSceneViewports.size(); i++)
        {
            gameSceneViewports[i].renderUpdate();
        }
        window.updateScreen();
    }
    AudioManager::Instance().stopMusic();
}

void GameInstance::quitEventCallback()
{
    mRunning = false;
}
