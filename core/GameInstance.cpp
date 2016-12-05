#include "include/global.hpp"

GameInstance::GameInstance()
{

}

GameInstance::~GameInstance()
{

}

bool GameInstance::init()
{
    SDL_Log("GameInstance::init \n");
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

    // Event mAudioManager
    EventManager::getInstance()->configure(&AudioManager::Instance());

    // scenemanaager
    SceneManager::getInstance()->init();

    return true;
}

void GameInstance::run()
{
    InputEventManager::getInstance()->registerQuitEventObserver(this);
    mRunning  = true;

    while ( mRunning )
    {
        InputEventManager::getInstance()->pollEventQueue();
        SceneManager::getInstance()->updateActiveScene();
    }
}

void GameInstance::quitEventCallback()
{
    mRunning = false;
}
